#include "ShapePainter.h"

#include <QPainter>

ShapePainter::ShapePainter()
{
    setAppearenceOfPoints(ALL_OTHER, SQUARE, Qt::GlobalColor::yellow);
    setAppearenceOfPoints(SHAPE_OTHER, TRIANGLE, Qt::GlobalColor::blue);
    setAppearenceOfPoints(SHAPE_MAIN, CIRCLE, Qt::GlobalColor::red);
    setShapeLinesColor(Qt::GlobalColor::lightGray);
}

void ShapePainter::setAppearenceOfPoints(TypeOfPoint type, ShapeOfPoint shape, Qt::GlobalColor color)
{
    switch (type) {
    case ALL_OTHER:
        otherPoint = shape;
        otherPointColor = color;
        break;
    case SHAPE_OTHER:
        otherShapePoint = shape;
        otherShapePointColor = color;
        break;
    case SHAPE_MAIN:
        mainShapePoint = shape;
        mainShapePointColor = color;
        break;
    }
}

void ShapePainter::setShapeLinesColor(Qt::GlobalColor color)
{
    shapeLinesColor = color;
}

QImage ShapePainter::drawShape(QImage &image, SetOfStars &setOfStars, SetOfIndices &setOfIndices)
{
    if (setOfIndices.size() < MIN_SIZE_OF_SET_OF_INDICES)
        return image;

    QImage resultImage = image;
    QPainter painter(&resultImage);

    // Draw shape pointer
    for (size_t i = 0; i < setOfIndices.size(); ++i) {
        size_t starIdx = setOfIndices[i];
        const auto &point = setOfStars[starIdx].second;

        // the first element is the index of main star in thr shape
        if (i == 0) { // main pointer in the shape
            drawPoint(painter, QPointF(point.x(), point.y()), mainShapePoint, mainShapePointColor);

            const auto &lastPoint = setOfStars[setOfIndices.back()].second;
            painter.setPen(QPen(Qt::lightGray, 1));
            painter.drawLine(QPointF(lastPoint.x(), lastPoint.y()), QPointF(point.x(), point.y()));
        } else { // all other points in the shape
            drawPoint(painter, QPointF(point.x(), point.y()), otherShapePoint, otherShapePointColor);

            const auto &prevPoint = setOfStars[setOfIndices[i - 1]].second;
            painter.setPen(QPen(Qt::lightGray, 1));
            painter.drawLine(QPointF(prevPoint.x(), prevPoint.y()), QPointF(point.x(), point.y()));
        }
    }

    // Draw remaining points ==> all other
    for (size_t index = 0; index < setOfStars.size(); ++index) {
        if (std::find(setOfIndices.begin(), setOfIndices.end(), index) == setOfIndices.end()) {
            const auto &star = setOfStars[index].second;
            drawPoint(painter, QPointF(star.x(), star.y()), otherPoint, otherPointColor);
        }
    }

    return resultImage;
}

QImage ShapePainter::drawAllStars(QImage &image, SetOfStars &setOfStars)
{
    QImage resultImage = image;
    QPainter painter(&resultImage);

    for (const auto &star : setOfStars) {
        drawPoint(painter, QPointF(star.second.x(), star.second.y()), otherPoint, otherPointColor);
    }

    return resultImage;
}

void ShapePainter::drawPoint(QPainter &painter,
                             const QPointF &point,
                             const ShapeOfPoint form,
                             const QColor &color)
{
    const double shapePixelSize = 10;

    painter.setPen(QPen(color, 1));
    switch (form) {
    case TRIANGLE: {
        QPointF points[3] = {QPointF(point.x(), point.y() - shapePixelSize),
                             QPointF(point.x() - shapePixelSize, point.y() + shapePixelSize),
                             QPointF(point.x() + shapePixelSize, point.y() + shapePixelSize)};
        painter.drawPolygon(points, 3);
        break;
    }
    case SQUARE: {
        painter.drawRect(point.x() - shapePixelSize,
                         point.y() - shapePixelSize,
                         shapePixelSize * 2,
                         shapePixelSize * 2);
        break;
    }
    case CIRCLE: {
        painter.drawEllipse(QPointF(point.x(), point.y()), shapePixelSize, shapePixelSize);
        break;
    }
    }
}

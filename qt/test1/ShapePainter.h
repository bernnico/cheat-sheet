#ifndef SHAPEPAINTER_H
#define SHAPEPAINTER_H

#include <Eigen/Dense>
#include <utility>
#include <vector>

// #include <QColor>
#include "qnamespace.h"
// #include "qtconfigmacros.h"

QT_BEGIN_NAMESPACE
class QImage;
class QPainter;
class QPointF;
class QColor;
QT_END_NAMESPACE

typedef std::vector<std::pair<int, Eigen::Vector2d>> SetOfStars;
typedef std::vector<size_t> SetOfIndices; // Indices of the stars in the 'SetOfStars' set
                                          // that belong to the shape

constexpr size_t MIN_SIZE_OF_SET_OF_INDICES = 3;

class ShapePainter
{
public:
    enum TypeOfPoint { ALL_OTHER, SHAPE_OTHER, SHAPE_MAIN };
    enum ShapeOfPoint { TRIANGLE, SQUARE, CIRCLE };

    ShapePainter();

    void setAppearenceOfPoints(TypeOfPoint type, ShapeOfPoint shape, Qt::GlobalColor color);
    void setShapeLinesColor(Qt::GlobalColor color);

    QImage drawShape(QImage &image, SetOfStars &setOfStars, SetOfIndices &setOfIndices);
    QImage drawAllStars(QImage &image, SetOfStars &setOfStars);

private:
    void drawPoint(QPainter &painter,
                   const QPointF &point,
                   const ShapeOfPoint form,
                   const QColor &color);

private:
    ShapeOfPoint otherPoint, otherShapePoint, mainShapePoint;
    Qt::GlobalColor otherPointColor, otherShapePointColor, mainShapePointColor;
    Qt::GlobalColor shapeLinesColor;
};

#endif // SHAPEPAINTER_H

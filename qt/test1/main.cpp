#include <QApplication>
#include <QImage>
#include <QLabel>
#include <QPainter>
#include <Eigen/Dense>
#include <algorithm>
#include <vector>

// TODO ===> Homework

typedef std::vector<std::pair<int, Eigen::Vector2d>> SetOfStars;
typedef std::vector<size_t> SetOfIndices;

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

void drawPoint(QPainter &painter,
               const Eigen::Vector2d &point,
               const QString &form,
               const QColor &color)
{
    painter.setPen(QPen(color, 2));
    if (form == "circle") {
        painter.drawEllipse(QPointF(point.x(), point.y()), 5, 5);
    } else if (form == "square") {
        painter.drawRect(point.x() - 5, point.y() - 5, 10, 10);
    } else if (form == "triangle") {
        // ...
    }
}

QImage drawShape(QImage &image, SetOfStars &setOfStars, SetOfIndices &setOfIndices)
{
    if (setOfIndices.size() < 3)
        return image; // Ensure there are at least 3 points to form a shape

    QPainter painter(&image);

    // Draw selected points with circles and connect them with lines
    for (size_t i = 0; i < setOfIndices.size(); ++i) {
        size_t index = setOfIndices[i];
        const auto &point = setOfStars[index].second;

        QColor color = (i == 0) ? Qt::yellow : Qt::blue;
        drawPoint(painter, point, "circle", color);

        if (i > 0) {
            const auto &prevPoint = setOfStars[setOfIndices[i - 1]].second;
            painter.setPen(QPen(Qt::lightGray, 2));
            painter.drawLine(QPointF(prevPoint.x(), prevPoint.y()), QPointF(point.x(), point.y()));
        } else {
            // const auto &firstPoint = setOfStars[setOfIndices[0]].second;
            const auto &lastPoint = setOfStars[setOfIndices.back()].second;
            painter.setPen(QPen(Qt::lightGray, 2));
            painter.drawLine(QPointF(lastPoint.x(), lastPoint.y()), QPointF(point.x(), point.y()));
        }
    }

    // Draw remaining points with squares
    for (size_t index = 0; index < setOfStars.size(); ++index) {
        if (std::find(setOfIndices.begin(), setOfIndices.end(), index) == setOfIndices.end()) {
            const auto &star = setOfStars[index].second;
            drawPoint(painter, star, "square", Qt::green);
        }
    }

    return image;
}

#include "ShapePainter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Example usage
    QImage image(1000, 1000, QImage::Format_RGB32);
    image.fill(Qt::black);

    SetOfStars setOfStars = {{0, Eigen::Vector2d(500 - 123, 500 + 210)},
                             {1, Eigen::Vector2d(200, 100)},
                             {2, Eigen::Vector2d(500 - 55, 500 - 223)},
                             {3, Eigen::Vector2d(200, 200)},
                             {4, Eigen::Vector2d(500 + 32, 500 - 300)},
                             {5, Eigen::Vector2d(300, 300)}};

    SetOfIndices setOfIndices = {0, 2, 4};

    ShapePainter shapePainter;
    QImage resultImage = shapePainter.drawShape(image, setOfStars, setOfIndices);
    // QImage resultImage = shapePainter.drawAllStars(image, setOfStars);

    QLabel label;
    label.setPixmap(QPixmap::fromImage(resultImage));
    // label.setPixmap(QPixmap::fromImage(image));
    label.show();

    return app.exec();
}

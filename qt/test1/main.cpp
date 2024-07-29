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

void drawPoint(QPainter &painter,
               const Eigen::Vector2d &point,
               const QString &form,
               const QColor &color)
{
    painter.setPen(QPen(color, 2));
    if (form == "circle") {
        painter.drawEllipse(QPoint(point.x(), point.y()), 5, 5);
    } else if (form == "square") {
        painter.drawRect(point.x() - 5, point.y() - 5, 10, 10);
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
            painter.setPen(QPen(Qt::blue, 2));
            painter.drawLine(QPoint(prevPoint.x(), prevPoint.y()), QPoint(point.x(), point.y()));
        }
    }

    // Connect last point to the first
    const auto &firstPoint = setOfStars[setOfIndices[0]].second;
    const auto &lastPoint = setOfStars[setOfIndices.back()].second;
    painter.setPen(QPen(Qt::blue, 2));
    painter.drawLine(QPoint(lastPoint.x(), lastPoint.y()), QPoint(firstPoint.x(), firstPoint.y()));

    // Draw remaining points with squares
    for (const auto &star : setOfStars) {
        if (std::find(setOfIndices.begin(), setOfIndices.end(), star.first) == setOfIndices.end()) {
            drawPoint(painter, star.second, "square", Qt::green);
        }
    }

    return image;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Example usage
    QImage image(400, 400, QImage::Format_RGB32);
    image.fill(Qt::white);

    SetOfStars setOfStars = {{0, Eigen::Vector2d(100, 100)},
                             {1, Eigen::Vector2d(200, 100)},
                             {2, Eigen::Vector2d(300, 100)},
                             {3, Eigen::Vector2d(200, 200)},
                             {4, Eigen::Vector2d(100, 300)},
                             {5, Eigen::Vector2d(300, 300)}};

    SetOfIndices setOfIndices = {0, 2, 4};

    QImage resultImage = drawShape(image, setOfStars, setOfIndices);

    QLabel label;
    label.setPixmap(QPixmap::fromImage(resultImage));
    label.show();

    return app.exec();
}

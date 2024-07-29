#include "MyTestClass.h"

#include <QDebug>
#include <QPainter>

MyTestClass::MyTestClass() {}

QPixmap MyTestClass::getDrawnPixmap()
{
    // Erstellen eines QImage mit einer Größe von 400x400 Pixel
    QImage image(400, 400, QImage::Format_RGB32);

    // Bildhintergrund auf weiß setzen
    image.fill(Qt::white);

    // Erstellen eines QPainter-Objekts, um auf das QImage zu zeichnen
    QPainter painter(&image);

    // Koordinaten der Mittelpunkte der gelben Kreise
    QPoint center1(100, 100);
    QPoint center2(300, 100);
    QPoint center3(200, 300);

    // Zeichne drei gelbe Kreise ohne Füllung
    painter.setPen(QPen(Qt::yellow, 5)); // Stiftfarbe gelb, Linienstärke 5 Pixel

    painter.drawEllipse(center1, 50, 50); // Erster Kreis
    painter.drawEllipse(center2, 50, 50); // Zweiter Kreis
    painter.drawEllipse(center3, 50, 50); // Dritter Kreis

    // Verbinde die Mittelpunkte der gelben Kreise mit einer roten Linie
    painter.setPen(QPen(Qt::red, 3)); // Stiftfarbe rot, Linienstärke 3 Pixel

    painter.drawLine(center1, center2); // Linie zwischen erstem und zweitem Kreis
    painter.drawLine(center2, center3); // Linie zwischen zweitem und drittem Kreis
    painter.drawLine(center3, center1); // Linie zwischen drittem und erstem Kreis

    // Zeichne drei blaue Quadrate ohne Füllung
    painter.setPen(QPen(Qt::blue, 5)); // Stiftfarbe blau, Linienstärke 5 Pixel

    painter.drawRect(50, 200, 100, 100);  // Erstes Quadrat
    painter.drawRect(250, 200, 100, 100); // Zweites Quadrat
    painter.drawRect(150, 50, 100, 100);  // Drittes Quadrat

    // Beenden des Malvorgangs
    painter.end();

    // Erstellen eines QPixmap zum Anzeigen des QImage
    return QPixmap::fromImage(image);
}

QImage MyTestClass::cvMatToQImage(const cv::Mat &mat)
{
    if (mat.empty()) {
        return QImage();
    }

    // Konvertierung der cv::Mat-Bilder in QImage
    switch (mat.type()) {
    case CV_8UC1: { // 8-bit, single channel
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8);
    }
    case CV_8UC3: { // 8-bit, 3 channel (BGR)
        // Umwandlung von BGR zu RGB
        cv::Mat rgb;
        cv::cvtColor(mat, rgb, cv::COLOR_BGR2RGB);
        return QImage(rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888);
    }
    case CV_8UC4: { // 8-bit, 4 channel (BGRA)
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGBA8888);
    }
    default: {
        qWarning() << "Unsupported cv::Mat format";
        return QImage();
    }
    }
}

cv::Mat MyTestClass::qImageToCvMat(const QImage &image)
{
    if (image.isNull()) {
        return cv::Mat();
    }

    switch (image.format()) {
    case QImage::Format_Grayscale8: {
        return cv::Mat(image.height(),
                       image.width(),
                       CV_8UC1,
                       (void *) image.bits(),
                       image.bytesPerLine())
            .clone();
    }
    case QImage::Format_RGB888: {
        // Umwandlung von RGB zu BGR
        cv::Mat rgb(image.height(),
                    image.width(),
                    CV_8UC3,
                    (void *) image.bits(),
                    image.bytesPerLine());
        cv::Mat bgr;
        cv::cvtColor(rgb, bgr, cv::COLOR_RGB2BGR);
        return bgr.clone();
    }
    case QImage::Format_RGBA8888: {
        // Umwandlung von RGBA zu BGRA
        cv::Mat rgba(image.height(),
                     image.width(),
                     CV_8UC4,
                     (void *) image.bits(),
                     image.bytesPerLine());
        cv::Mat bgra;
        cv::cvtColor(rgba, bgra, cv::COLOR_RGBA2BGRA);
        return bgra.clone();
    }
    default: {
        qWarning() << "Unsupported QImage format";
        return cv::Mat();
    }
    }
}

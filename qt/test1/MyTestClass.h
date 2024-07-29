#ifndef MYTESTCLASS_H
#define MYTESTCLASS_H

#include <QImage>
#include <QPixmap>

#include <opencv2/opencv.hpp>

class MyTestClass
{
public:
    MyTestClass();

    static QPixmap getDrawnPixmap();

    static QImage cvMatToQImage(const cv::Mat &mat);
    static cv::Mat qImageToCvMat(const QImage &image);
};
#endif // MYTESTCLASS_H

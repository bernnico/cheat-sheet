#include <QApplication>
#include <QLabel>

#include "MyTestClass.h"

QPixmap getDrawnPixmap();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Anzeigen des QImage in einem QLabel
    QPixmap pixmap = MyTestClass::getDrawnPixmap();
    QLabel label;
    label.setPixmap(pixmap);
    label.show();

    return app.exec();
}

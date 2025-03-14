QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MyTestClass.cpp \
    ShapePainter.cpp \
    ToggleWidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    MyTestClass.h \
    ShapePainter.h \
    ToggleWidget.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32: {
    include("opencv.pri")
}

unix: !macx{
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}

unix: macx{
INCLUDEPATH += "/usr/local/include"
LIBS += -L"/usr/local/lib" \
    -lopencv_world
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

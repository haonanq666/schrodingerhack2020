QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ball.cpp \
    collision.cpp \
    fan.cpp \
    gameover.cpp \
    main.cpp \
    mainwindow.cpp \
    startdialog.cpp \
    v2.cpp

HEADERS += \
    Collision.h \
    ball.h \
    fan.h \
    gameover.h \
    mainwindow.h \
    startdialog.h \
    v2.h

FORMS += \
    gameover.ui \
    mainwindow.ui \
    startdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=

QT       += core gui opengl widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

LIBS = -lglu32 -lOpengl32

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    charactercontroller.cpp \
    collider.cpp \
    collisionmanager.cpp \
    displaymanager.cpp \
    dungeonmanager.cpp \
    ennemy.cpp \
    entitiesmanager.cpp \
    entity.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    projectilebehaviour.cpp \
    shooter.cpp

HEADERS += \
    charactercontroller.h \
    collider.h \
    collisionmanager.h \
    displaymanager.h \
    dungeonmanager.h \
    ennemy.h \
    entitiesmanager.h \
    entity.h \
    mainwindow.h \
    player.h \
    projectilebehaviour.h \
    shooter.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

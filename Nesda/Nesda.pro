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
    door.cpp \
    dungeonmanager.cpp \
    ennemy.cpp \
    entitiesmanager.cpp \
    entity.cpp \
    gamemanager.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    projectilebehaviour.cpp \
    roommanager.cpp \
    shooter.cpp \
    target.cpp

HEADERS += \
    charactercontroller.h \
    collider.h \
    collisionmanager.h \
    displaymanager.h \
    door.h \
    dungeonmanager.h \
    ennemy.h \
    entitiesmanager.h \
    entity.h \
    gamemanager.h \
    mainwindow.h \
    player.h \
    projectilebehaviour.h \
    roommanager.h \
    shooter.h \
    target.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

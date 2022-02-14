#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H
#include <QGLWidget>
#include <QtWidgets>
#include <QWidget>
#include <QTimer>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include "windows.h"
#include "entity.h"
#include "player.h"
#include "charactercontroller.h"
#include "projectilebehaviour.h"
#include "collisionmanager.h"
#include "entitiesmanager.h"

class DisplayManager : public QGLWidget
{
    friend class QMainWindow;
    friend class MainWindow;
public:
    explicit DisplayManager(QWidget *parent = 0);

    void initializeGL();
    void paintGL(); // Display the scene Gl
    void resizeGL(int width, int height);
    void DrawSquare(Entity entity);
    void DrawCircle(ProjectileBehaviour ball);
    void DrawCircle(Entity entity);

protected:
    // Mouse Management
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    QTimer _timer; // To update the scene
    float _X, _Y ,_Z; // Translation
    float x;
    float y;
    vector<Entity> v_entity;
    QPoint _lastPosMouse; // To keep the last position of the mouse
    CharacterController characterController;
    ProjectileBehaviour tempBall;
    CollisionManager collisionManager;
    EntitiesManager entitiesManager;
};

#endif // DISPLAYMANAGER_H

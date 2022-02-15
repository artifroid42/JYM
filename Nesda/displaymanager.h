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
#include "dungeonmanager.h"
#include "QThread"

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

    ~DisplayManager()
    {
      QMetaObject::invokeMethod(this,"Cleanup");
      m_thread->wait();
    };

protected:
    // Mouse Management
    void mousePressEvent(QMouseEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);
    //void wheelEvent(QWheelEvent *event);

private slots :
    void Cleanup() { m_thread->quit(); }
private:
    QTimer _timer; // To update the scene
    float _X, _Y ,_Z; // Translation
    float x;
    float y;
    vector<Entity> v_entity;
    QVector3D _lastPosMouse; // To keep the last position of the mouse
    CharacterController characterController;
    ProjectileBehaviour tempBall;
    CollisionManager collisionManager;
    EntitiesManager entitiesManager;
    QTime timer;
    DungeonManager dungeonManager;
    std::unique_ptr<QThread> m_thread;
    QMouseEvent *event;
};

#endif // DISPLAYMANAGER_H

#include "displaymanager.h"
#include <GL/glu.h>

#include "QDebug"
#include "QDir"
#include <iostream>
#include <filesystem>
#include "fstream"
#include "iostream"
#include "player.h"

using namespace std;

DisplayManager::DisplayManager(QWidget *parent) : QGLWidget(parent), _X(0), _Y(0), _Z(-10)
{
    timer.start();
    collisionManager = CollisionManager();
    entitiesManager = EntitiesManager();
    entitiesManager.CreateObstacles();
    Player player = Player(QVector3D(0,0,0),QVector3D(0,0,0),QVector3D(1,1,0), QVector3D(0, 1, 0));
    player.collider.SetWorldPosition(player.worldPosition);
    characterController = CharacterController(player);

    // Update the scene
    connect( &_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    _timer.start(16); // Starts or restarts the timer with a timeout interval of 16 milliseconds.
    setMouseTracking(true);
//    v_entity.push_back(Entity(QVector3D(0,0,0),QVector3D(0,0,0),QVector3D(1,2,0)));
    player = Player(QVector3D(0,0,0),QVector3D(0,0,0),QVector3D(1,1,0), QVector3D(0, 1, 0));
    characterController = CharacterController(player);
}

void DisplayManager::initializeGL()
{
    // background color
    glClearColor(0.07, 0.04, 0.02, 1);

    // Shader
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    fprintf(stderr, "initialisation du Gl\n");
}

void DisplayManager::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Center the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, _Z);

    // Rotation
    //glRotatef(0.f, 90.0f, 0.0, 0.0f);

    //inputs
    if (GetKeyState('S') < 0) {
        characterController.direction.setY(-1);
    }
    else if (GetKeyState('Z') < 0) {
        characterController.direction.setY(1);
    }
    if (GetKeyState('Q') < 0) {
        characterController.direction.setX(-1);
    }
    else if (GetKeyState('D') < 0) {
        characterController.direction.setX(1);
    }

    for(ProjectileBehaviour& ball : entitiesManager.balls){
        ball.MoveForward();
        DrawCircle(ball);
    }

    for(Entity& obstacle : entitiesManager.rectObstacles) {

        //handle collisions player
        int collisionDirection = collisionManager.IsRectCollidingWithRect(characterController.player.collider, obstacle.collider);
        if(collisionDirection == 0 && characterController.direction.y() < 0)
            characterController.direction.setY(0);
        else if(collisionDirection == 2 && characterController.direction.y() > 0)
            characterController.direction.setY(0);
        else if(collisionDirection == 1 && characterController.direction.x() < 0.0)
            characterController.direction.setX(0);
        else if(collisionDirection == 3 && characterController.direction.x() > 0.0)
            characterController.direction.setX(0);

        //draw
        DrawSquare(obstacle);

        for(ProjectileBehaviour& ball : entitiesManager.balls) {
            //handle collisions balls
            int ballCollisionDirection = collisionManager.IsCircleCollidingWithRect(ball.collider, obstacle.collider);

            if(ballCollisionDirection >= 0){
                ball.RectBounce(ballCollisionDirection);
            }
        }
    }
    for(ProjectileBehaviour& ball : entitiesManager.balls) {
        for(Entity& obstacle : entitiesManager.circleObstacles) {
            //handle collisions balls
            QVector3D collisionNormal = collisionManager.IsCircleCollidingWithCircle(ball.collider, obstacle.collider);
            if(collisionNormal != QVector3D(0, 0, 0)) {
                ball.NormalBounce(collisionNormal);
            }
        }
        //draw
        DrawCircle(ball);
    }

    for(Entity& obstacle : entitiesManager.circleObstacles) {
        vector<int> collisionDirections = collisionManager.IsRectCollidingWithCircle(characterController.player.collider, obstacle.collider);
        for(int direction : collisionDirections) {
            if(direction == 0 && characterController.direction.y() < 0)
                characterController.direction.setY(0);
            else if(direction == 2 && characterController.direction.y() > 0)
                characterController.direction.setY(0);
            else if(direction == 3 && characterController.direction.x() < 0)
                characterController.direction.setX(0);
            else if(direction == 1 && characterController.direction.x() > 0)
                characterController.direction.setX(0);
        }

        DrawCircle(obstacle);
    }


    //apply movements
    characterController.applyMovements();

    //end update loop
    characterController.ResetDirection();
    DrawSquare(characterController.player);

    entitiesManager.checkBallsToDelete(timer.elapsed());
}

void DisplayManager::DrawSquare(Entity entity)
{
    x = entity.worldPosition.x() + entity.collider.localPt1.x();
    y = entity.worldPosition.y() + entity.collider.localPt1.y();

    glBegin(GL_QUADS);
        glColor3f(entity.color.x(), entity.color.y(), entity.color.z()); // Couleurs
        glVertex3f(x,y,0);
        glVertex3f(x,y+entity.collider.localPt2.y(),0);
        glVertex3f(x+entity.collider.localPt2.x(),y+entity.collider.localPt2.y(),0);
        glVertex3f(x+entity.collider.localPt2.x(),y,0);
        glEnd();
}

void DisplayManager::DrawCircle(ProjectileBehaviour ball){
    glColor3f(1.0, 1.0, 1.0);

   glBegin(GL_TRIANGLE_FAN);

   float cx = ball.worldPosition.x();
   float cy = ball.worldPosition.y();
   float radius = ball.collider.Radius;

   glVertex2f(cx, cy); // Center
   for(float i = 0.0f; i <= 360; i++)
           glVertex2f(radius*cos(M_PI * i / 180.0) + cx, radius*sin(M_PI * i / 180.0) + cy);
   glEnd();
}

void DisplayManager::DrawCircle(Entity entity) {
    glColor3f(entity.color.x(), entity.color.y(), entity.color.z());

   glBegin(GL_TRIANGLE_FAN);

   float cx = entity.worldPosition.x();
   float cy = entity.worldPosition.y();
   float radius = entity.collider.Radius;

   glVertex2f(cx, cy); // Center
   for(float i = 0.0f; i <= 360; i++)
           glVertex2f(radius*cos(M_PI * i / 180.0) + cx, radius*sin(M_PI * i / 180.0) + cy);
   glEnd();
}

void DisplayManager::resizeGL(int width, int height){

    glViewport(0, 0, width, height); //Viewport in the world window
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 3000.0f);

    updateGL();
}

// - - - - - - - - - - - - Mouse Management  - - - - - - - - - - - - - - - -
// When you click, the position of your mouse is saved
void DisplayManager::mousePressEvent(QMouseEvent *event)
{
    cout << "Piou piou" << endl;
    if( event != NULL ) {

        //400x 300y
        _lastPosMouse = event->pos();
        _lastPosMouse.setX((_lastPosMouse.x()-400)*0.01372);
        _lastPosMouse.setY((_lastPosMouse.y()-300)*-0.01372);
        // Do stuff
        cout << "pos souris x : " << _lastPosMouse.x() << endl << "pos souris y : " << _lastPosMouse.y() << endl;
        QVector3D spawnPosition = (characterController.player.collider.worldPt1 + characterController.player.collider.worldPt2) / 2;
        cout << "pos spawn x : " << spawnPosition.x() << endl << "pos spawn y : " << spawnPosition.y() << endl;
        ProjectileBehaviour ball = ProjectileBehaviour(spawnPosition, 0.1, 0.1, QVector3D(1,1,0),
                                                       QVector3D(_lastPosMouse.x(),_lastPosMouse.y(),0)-spawnPosition)
                                                       QVector3D(_lastPosMouse.x(),_lastPosMouse.y(),0)-characterController.player.worldPosition, timer.elapsed())
                                                       /*QVector3D(-2,5,0))*/;
        entitiesManager.AddBall(ball);
        updateGL();
    }
}

// Mouse movement management
void DisplayManager::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - _lastPosMouse.x();
    int dy = event->y() - _lastPosMouse.y();

//    cout << "Souris qui bouge sur x : " << dx << endl;
//    cout << "Souris qui bouge sur y : " << dy << endl;
    if( event != NULL )
    {
        // Do stuff
        updateGL();
    }
}

// Mouse Management for the zoom (for instance)
void DisplayManager::wheelEvent(QWheelEvent *event) {
    QPoint numDegrees = event->angleDelta();
    double stepZoom = 0.25;
    if (!numDegrees.isNull())
    {
      _Z = (numDegrees.x() > 0 || numDegrees.y() > 0) ? _Z + stepZoom : _Z - stepZoom;
    }
}

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
    ball = ProjectileBehaviour(/*player.worldPosition*/QVector3D(0,0,0), 0.5, 0.1, QVector3D(1, 1, 1));
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


    for (int i = 0; i < v_entity.size(); i++)
    {
        //cout << "vector size : " << v_entity.size() << endl;
        //DrawCaree(v_entity.at(i));
    }

      DrawCircle(ball);

        //inputs
        if (GetKeyState('S') < 0) {
            characterController.direction.setY(-1);
            //ball.RectBounce(2);
            ball.NormalBounce(QVector3D(0, -1, 0));
        }
        else if (GetKeyState('Z') < 0) {
            characterController.direction.setY(1);
             //ball.RectBounce(0);
            ball.NormalBounce(QVector3D(0, 1, 0));
        }
        if (GetKeyState('Q') < 0) {
            characterController.direction.setX(-1);
             //ball.RectBounce(1);
            ball.NormalBounce(QVector3D(-1, 0, 0));

        }
        else if (GetKeyState('D') < 0) {
            characterController.direction.setX(1);
             //ball.RectBounce(3);
            ball.NormalBounce(QVector3D(1, 0, 0));

        }

        if(ball.worldPosition.x() > 10)
        {
            ball.NormalBounce(QVector3D(-1, 0, 0));
        }
        else if(ball.worldPosition.x() < -10)
        {
             ball.NormalBounce(QVector3D(1, 0, 0));
        }

        for(Entity obstacle : entitiesManager.rectObstacles) {

            //handle collisions
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
        }

        //apply movements
        characterController.applyMovements();
        ball.MoveForward();

        //end update loop
        characterController.ResetDirection();
        DrawSquare(characterController.player);
}

void DisplayManager::DrawSquare(Entity entity)
{
    x = entity.worldPosition.x() + entity.collider.localPt1.x();
    y = entity.worldPosition.y() + entity.collider.localPt1.y();

    //cout << "Je suis vivant" << endl;

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
        _lastPosMouse = event->pos();
        // Do stuff
        cout << "pos souris x : " << _lastPosMouse.x() << endl << "pos souris y : " << _lastPosMouse.y() << endl;
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

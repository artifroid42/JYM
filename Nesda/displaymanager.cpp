#include "displaymanager.h"
#include <GL/glu.h>

#include "QDebug"
#include "QDir"
#include <iostream>
#include <filesystem>
#include "fstream"
#include "iostream"

using namespace std;

DisplayManager::DisplayManager(QWidget *parent) : QGLWidget(parent), _X(0), _Y(0), _Z(-10)
{
    // Update the scene
    connect( &_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    _timer.start(16); // Starts or restarts the timer with a timeout interval of 16 milliseconds.
    setMouseTracking(true);

    v_entity.push_back(Entity(QVector3D(0,0,0),QVector3D(0,0,0),QVector3D(1,2,0)));


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

    /*
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0 ,0);
        glVertex3f(-0.5,0.8,0);
        glVertex3f(0,1.6,0);
        glVertex3f(0.5,0.8,0);

        glColor3f(0, 0 ,1);
        glVertex3f(0,0,0);
        glVertex3f(0.5,0.8,0);
        glVertex3f(1,0,0);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(0, 1 ,0);
        glVertex3f(-1,0,0);
        glVertex3f(-0.5,0.8f,0);
        glVertex3f(0,0,0);
        glVertex3f(-1,0,0);
    glEnd();*/

    /*
    glBegin(GL_QUADS);
        glColor3f(0,1,1);
        glVertex3f(x,y,0);
        glVertex3f(x,y+1,0);
        glVertex3f(x+1,y+1,0);
        glVertex3f(x+1,y,0);
        glEnd();
        //std::cout << "oui" << endl;
*/
    for (int i = 0; i < v_entity.size(); i++)
    {
        //cout << "vector size : " << v_entity.size() << endl;
        DrawCaree(v_entity.at(i));
    }


        if (GetKeyState('S') < 0) {
            // The S key is down.
            cout << "S est appuye" << endl;
            y -= 0.01;
        }
        if (GetKeyState('Z') < 0) {
            // The S key is down.
            cout << "Z est appuye" << endl;
            y += 0.01;
        }
        if (GetKeyState('Q') < 0) {
            // The S key is down.
            cout << "Q est appuye" << endl;
            x -= 0.01;
        }
        if (GetKeyState('D') < 0) {
            // The S key is down.
            cout << "D est appuye" << endl;
            x += 0.01;
        }


}

void DisplayManager::DrawCaree(Entity entity)
{
    x = entity.worldPosition.x() + entity.collider.localPt2.x();
    y = entity.worldPosition.y() + entity.collider.localPt2.y();

    //cout << "Je suis vivant" << endl;

    glBegin(GL_QUADS);
        glColor3f(0,1,1); // Couleurs
        glVertex3f(x,y,0);
        glVertex3f(x,y+entity.collider.localPt2.y(),0);
        glVertex3f(x+entity.collider.localPt2.x(),y+entity.collider.localPt2.y(),0);
        glVertex3f(x+entity.collider.localPt2.x(),y,0);
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

    cout << "Souris qui bouge sur x : " << dx << endl;
    cout << "Souris qui bouge sur y : " << dy << endl;
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

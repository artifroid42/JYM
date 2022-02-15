#include "projectilebehaviour.h"
#include <iostream>
#include <math.h>
#include <QQuaternion>
#define PI 3.14

ProjectileBehaviour::ProjectileBehaviour()
{

}

ProjectileBehaviour::ProjectileBehaviour(QVector3D spawnPos, float radius, float speed, QVector3D color, QVector3D forward, int currentTime) : Entity(spawnPos, radius, color)
{
    _speed = speed;
    SetForward(forward);
    spawnTime = currentTime;
}

void ProjectileBehaviour::SetForward(QVector3D forward){
    _forward = forward.normalized();
    //if(_forward.x() != 0 && _forward.y() != 0)
        //_speed *= 0.7;
}

void ProjectileBehaviour::MoveForward(){
    worldPosition += _forward * _speed;
    collider.SetWorldPosition(worldPosition);
}

//ID : 0 = top, 1 = right, 2 = bottom, 3 = left
void ProjectileBehaviour::RectBounce(int a_sideID){
    switch (a_sideID) {
    case 0:
        if(_forward.y() < 0)
            _forward.setY(_forward.y() * -1);
        break;
    case 1:
         if(_forward.x() < 0)
            _forward.setX(_forward.x() * -1);
        break;
    case 2:
         if(_forward.y() > 0)
             _forward.setY(_forward.y() * -1);
        break;
    case 3:
         if(_forward.x() > 0)
            _forward.setX(_forward.x() * -1);
        break;
    default:
        cout << "SIDE ID NOT CORRECT" << endl;
        break;
    }
}

void ProjectileBehaviour::NormalBounce(QVector3D a_normal){
    _forward = _forward * -1;

    float teta = acos((QVector3D::dotProduct(_forward, a_normal)) / _forward.length()*a_normal.length());

    if(teta < PI/2){
        int orientation = (QVector3D::crossProduct(_forward, a_normal).z() > 0) ? 1 : -1;
        float angle = orientation * 2 * teta;
        _forward = QVector3D(cos(angle) * _forward.x() - sin(angle) * _forward.y(), sin(angle) * _forward.x() + cos(angle) * _forward.y(), 0).normalized();
    }
    else{
        _forward = _forward * -1;
    }
}

#include "projectilebehaviour.h"
#include <iostream>
#include <math.h>
#include <QQuaternion>
#define PI 3.14

ProjectileBehaviour::ProjectileBehaviour()
{

}

ProjectileBehaviour::ProjectileBehaviour(QVector3D spawnPos, float radius, float speed, QVector3D color) : Entity(spawnPos, radius, color)
{
    _speed = speed;
    SetFoward(QVector3D(-2,5,0));
}

void ProjectileBehaviour::SetFoward(QVector3D forward){
    _forward = forward.normalized();
    //if(_forward.x() != 0 && _forward.y() != 0)
        //_speed *= 0.7;
}

void ProjectileBehaviour::MoveForward(){
    worldPosition += _forward * _speed;
    //cout << worldPosition.x() << " " << worldPosition.y() << endl;
    //cout << _forward.x() << " " << _forward.y() << endl;
    //cout << _speed << endl;
}

//ID : 0 = top, 1 = right, 2 = bottom, 3 = left
void ProjectileBehaviour::RectBounce(int a_sideID){
    switch (a_sideID) {
    case 0:
        _forward.setY(_forward.y() * -1);
        break;
    case 1:
        _forward.setX(_forward.x() * -1);
        break;
    case 2:
        _forward.setY(_forward.y() * -1);
        break;
    case 3:
        _forward.setX(_forward.x() * -1);
        break;
    default:
        cout << "SIDE ID NOT CORRECT" << endl;
        break;
    }
}

void ProjectileBehaviour::NormalBounce(QVector3D a_normal){
    //A = acos(AB.AC/(||AB||*||AC||))
    _forward = _forward * -1;

    float teta = acos((QVector3D::dotProduct(_forward, a_normal)) / _forward.length()*a_normal.length());
    cout << teta * 57.2958 << endl;

    cout << "FORWARD: " << _forward.x() << " " << _forward.y() << endl;
    cout << "NORMAL: " << a_normal.x() << " " << a_normal.y() << endl;

//    QQuaternion quaternion = QQuaternion(1, 0, 0, teta);
//    QVector3D newDir = quaternion.rotatedVector(a_normal.normalized());


    //_forward = newDir.normalized();
    if(teta < PI/2){
        int orientation = (QVector3D::crossProduct(_forward, a_normal).z() > 0) ? 1 : -1;
        float angle = orientation * 2 * teta;
        _forward = QVector3D(cos(angle) * _forward.x() - sin(angle) * _forward.y(), sin(angle) * _forward.x() + cos(angle) * _forward.y(), 0).normalized();
        cout << "NEW FORWARD: " << _forward.x() << " " << _forward.y() << endl;

    }
    else{
        _forward = _forward * -1;
    }
}

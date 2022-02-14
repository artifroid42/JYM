#include "projectilebehaviour.h"
#include <iostream>

ProjectileBehaviour::ProjectileBehaviour()
{

}

ProjectileBehaviour::ProjectileBehaviour(QVector3D spawnPos, float radius, float speed, QVector3D color) : Entity(spawnPos, radius, color)
{
    _speed = speed;
    SetFoward(QVector3D(5,10,0));
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
    //_forward = _forward + -a_normal.normalized();
    QVector3D medianPoint =
}

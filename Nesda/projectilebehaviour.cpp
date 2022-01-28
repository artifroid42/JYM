#include "projectilebehaviour.h"

ProjectileBehaviour::ProjectileBehaviour()
{

}

ProjectileBehaviour::ProjectileBehaviour(QVector3D spawnPos, float radius, QVector3D color) : Entity(spawnPos, radius, color)
{

}

void ProjectileBehaviour::SetFoward(QVector3D forward){
    _forward = forward;
}

void ProjectileBehaviour::MoveForward(){

}

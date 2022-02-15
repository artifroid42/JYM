#include "roommanager.h"


RoomManager::RoomManager()
{

}


void RoomManager::CreateDoors(){
    //Create doors
    doors.insert(doors.cend(), Door(QVector3D(-8,4,0),QVector3D(0,0,0),QVector3D(14,0.3,0), QVector3D(1, 0, 0), 0));
    doors.insert(doors.cend(), Door(QVector3D(-8,-4,0),QVector3D(0,0,0),QVector3D(14,0.3,0), QVector3D(1, 0, 0), 1));
    doors.insert(doors.cend(), Door(QVector3D(-5.7,-4,0),QVector3D(0,0,0),QVector3D(0.3,8,0), QVector3D(1, 0, 0), 2));
    doors.insert(doors.cend(), Door(QVector3D(5.2,-4,0),QVector3D(0,0,0),QVector3D(0.3,8,0), QVector3D(1, 0, 0), 3));

    //    walls.insert(walls.cend(), Entity(QVector3D(-8,4,0),QVector3D(0,0,0),QVector3D(14,0.3,0), QVector3D(0.7, 0.7, 0.7)));
    //    walls.insert(walls.cend(), Entity(QVector3D(-8,-4,0),QVector3D(0,0,0),QVector3D(14,0.3,0), QVector3D(0.7, 0.7, 0.7)));
    //    walls.insert(walls.cend(), Entity(QVector3D(-5.7,-4,0),QVector3D(0,0,0),QVector3D(0.3,8,0), QVector3D(0.7, 0.7, 0.7)));
    //    walls.insert(walls.cend(), Entity(QVector3D(5.2,-4,0),QVector3D(0,0,0),QVector3D(0.3,8,0), QVector3D(0.7, 0.7, 0.7)));


    for(Door door : doors) {
        door.collider.SetWorldPosition(door.worldPosition); //A faire dans le display ?
        currentDoorIDs.insert(currentDoorIDs.cend(), door.doorID);
    }
}

void RoomManager::GoToNextRoom(int lastDoorID){
    currentDoorIDs.clear();
    //Faire un dungeonManager.GetCurrentDoorsIds() dans le SetCurrentDoorIDs()
}

void RoomManager::SetCurrentDoorIDs(vector<int> doorIDs){
    currentDoorIDs = doorIDs;
}

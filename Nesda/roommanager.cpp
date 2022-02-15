#include "roommanager.h"


RoomManager::RoomManager()
{

}


void RoomManager::CreateDoors(){
    //Create doors
    doors.insert(doors.cend(), Door(QVector3D(-1,3.9,0),QVector3D(0,0,0),QVector3D(2,0.3,0), QVector3D(1, 0, 0), 0));
    doors.insert(doors.cend(), Door(QVector3D(-5.6,-1,0),QVector3D(0,0,0),QVector3D(0.3,2,0), QVector3D(1, 0, 0), 3));
    doors.insert(doors.cend(), Door(QVector3D(-1,-3.9,0),QVector3D(0,0,0),QVector3D(2,0.3,0), QVector3D(1, 0, 0), 2));
    doors.insert(doors.cend(), Door(QVector3D(5.1,-1,0),QVector3D(0,0,0),QVector3D(0.3,2,0), QVector3D(1, 0, 0), 1));

    for(Door door : doors) {
        door.collider.SetWorldPosition(door.worldPosition);
        currentDoorIDs.insert(currentDoorIDs.cend(), door.doorID);
    }
}

void RoomManager::GoToNextRoom(int lastDoorID){
    currentDoorIDs.clear();
    switch (lastDoorID) {
        case 0 :
            currentRoomPosY--;
            break;
        case 1 :
            currentRoomPosX++;
            break;
        case 2 :
            currentRoomPosY++;
            break;
        case 3 :
            currentRoomPosX--;
            break;
    }
    //Faire un dungeonManager.GetCurrentDoorsIds() dans le SetCurrentDoorIDs()
}

void RoomManager::SetCurrentDoorIDs(vector<int> doorIDs){
    currentDoorIDs = doorIDs;
}

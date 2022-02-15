#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H
#include <iostream>
#include "vector"
#include "Entity.h"
#include "door.h"

using namespace std;

class RoomManager
{
public:
    RoomManager();

    vector<int> currentDoorIDs;
    vector<Door> doors;

    int currentRoomPosX;
    int currentRoomPosY;

    void CreateDoors(); //dungeonManager.GetDoors()
    void GoToNextRoom(int doorID);
    void SetCurrentDoorIDs(vector<int>);
};

#endif // ROOMMANAGER_H

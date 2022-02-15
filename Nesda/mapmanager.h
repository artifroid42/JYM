#include "room.h"


#ifndef MAPMANAGER_H
#define MAPMANAGER_H


class Mapmanager
{
public:
    Mapmanager();
    Mapmanager(vector<Room> rooms);
    vector<Room> _rooms;
    Room currentRoom;
    vector<Entity> currentObstcles;
    vector<Entity> currentDoors;

private:

    void OnDoorReached(int doorID);
};

#endif // MAPMANAGER_H

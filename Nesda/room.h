#include "entity.h"
#ifndef ROOM_H
#define ROOM_H


class Room
{
public:
    Room();
    Room(vector<Entity> obstacles, int doorIDs);
    vector<int> _doorIDs;
    enum RoomsVoisines { // On parlait de Dictionnary, j'ai peut être pas bien compris ce qui était recherché mais ça m'a fait pensé à ça ?
        ROOM1 = 0,
        ROOM2 = 1,
        ROOM3 = 2,
        ROOM4 = 3
    };
    Entity button;
    vector<Entity> _obstacles;
    vector<Entity> _doors;
    bool IsLastRoom;


private:



};

#endif // ROOM_H

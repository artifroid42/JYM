#include "room.h"

Room::Room()
{

}

Room::Room(vector<Entity> obstacles, int doorIDs) // Lorsqu'on créer un objet de la classe on récupère une liste d'obstacles et ID des portes
{
    _obstacles = obstacles;
    _doorIDs.push_back(doorIDs);
}


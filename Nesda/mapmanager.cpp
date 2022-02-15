#include "mapmanager.h"
#include "windows.h"

Mapmanager::Mapmanager()
{

}

Mapmanager::Mapmanager(vector <Room> rooms)
{
    _rooms = rooms;
}

void Mapmanager::OnDoorReached(int doorID)
{
   if (GetKeyState('P') < 0) {
        // Remplacer la map actuelle par une map compatible
    }
}



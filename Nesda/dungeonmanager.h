#ifndef DUNGEONMANAGER_H
#define DUNGEONMANAGER_H
#include "vector"
#include <stdlib.h>

using namespace std;

class DungeonManager
{
public:
    DungeonManager();
    int startX;
    int startY;
    void CreateDungeon(int size);
    vector<int> GetDoors(int x, int y);
    vector<vector<int>> dungeon = vector<vector<int>>();
private:
    int RandomInt(int min, int max);
    int dungeonSize = 0;
};

#endif // DUNGEONMANAGER_H

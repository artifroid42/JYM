#include "dungeonmanager.h"
#include "iostream"
#include "cmath"

DungeonManager::DungeonManager()
{
}

void DungeonManager::CreateDungeon(int size) {
    dungeonSize = size;
    for(int y=0; y<size; y++) {
        vector<int> line = vector<int>();
        for(int x=0; x<size; x++) {
            line.insert(line.cend(), 0);
        }
        dungeon.insert(dungeon.cend(), line);
    }

    //get 2 corners
    vector<vector<int>> positions = vector<vector<int>>();
    int randCorner = RandomInt(0, 3);
    if(randCorner == 0) {
        dungeon[0][0] = 1;
        positions.insert(positions.cend(), vector<int>{0, 0});
        startX = 0;
        startY = 0;
    }
    else if(randCorner == 1) {
        dungeon[0][size-1] = 1;
        positions.insert(positions.cend(), vector<int>{size-1, 0});
        startX = size-1;
        startY = 0;
    }
    else if(randCorner == 2) {
        dungeon[size-1][0] = 1;
        positions.insert(positions.cend(), vector<int>{0, size-1});
        startX = 0;
        startY = size-1;
    }
    else {
        dungeon[size-1][size-1] = 1;
        positions.insert(positions.cend(), vector<int>{size-1, size-1});
        startX = size-1;
        startY = size-1;
    }

    int corner = RandomInt(0, 3);
    while(corner == randCorner) {
        corner = RandomInt(0, 3);
    }
    if(corner == 0) {
        dungeon[0][0] = 1;
        positions.insert(positions.cend(), vector<int>{0, 0});
    }
    else if(corner == 1) {
        dungeon[0][size-1] = 1;
        positions.insert(positions.cend(), vector<int>{size-1, 0});
    }
    else if(corner == 2) {
        dungeon[size-1][0] = 1;
        positions.insert(positions.cend(), vector<int>{0, size-1});
    }
    else {
        dungeon[size-1][size-1] = 1;
        positions.insert(positions.cend(), vector<int>{size-1, size-1});
    }

    //get 2 random points
    vector<int> point = vector<int>{RandomInt(1, size-2), RandomInt(1, size-2)};
    dungeon[point[1]][point[0]] = 1;
    positions.insert(positions.cend(), point);

    vector<int> otherPoint = vector<int>{RandomInt(1, size-2), RandomInt(1, size-2)};
    while(otherPoint == point) {
        otherPoint = vector<int>{RandomInt(1, size-2), RandomInt(1, size-2)};
    }
    dungeon[otherPoint[1]][otherPoint[0]] = 1;
    positions.insert(positions.cend(), otherPoint);

//    for(int i=0; i<positions.size(); i++) {
//        cout<<positions[i][0]<<"-"<<positions[i][1]<<endl;
//    }

    //link points
    int positionsCount = positions.size();
    for(int i=0; i<positionsCount-1; i++) {
        int x = positions[0][0];
        int y = positions[0][1];
        vector<int> closestPoint;
        int distanceToClosestPoint = 99;
        for(int j=1; j<positionsCount-i; j++) {
            int distance = abs(positions[1][0] - positions[0][0]) + abs(positions[1][1] - positions[0][1]);
            distanceToClosestPoint = distance;
            closestPoint = positions[1];
        }
        if(distanceToClosestPoint == 99)
            break;
        int xDist = closestPoint[0] - x;
        int yDist = closestPoint[1] - y;

        for(int j=0; j<distanceToClosestPoint; j++) {
            int XorY = RandomInt(0, 1);
            if(yDist == 0 || XorY == 0) {
                if(xDist > 0) {
                    xDist--;
                    x++;
                } else {
                    xDist++;
                    x--;
                }
            } else {
                if(yDist > 0) {
                    yDist--;
                    y++;
                } else {
                    yDist++;
                    y--;
                }
            }
//            cout<<"x: "<<x<<" y: "<<y<<endl;
            dungeon[y][x] = 1;
        }

        positions.erase(positions.begin());
    }


    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cout<<dungeon[i][j];
        }
        cout<<endl;
    }
}

vector<int> DungeonManager::GetDoors(int x, int y) {
    vector<int> doors = vector<int>();
    if(y-1 >= 0 && dungeon[y-1][x] > 0)
        doors.insert(doors.cend(), 0);
    if(x-1 >= 0 && dungeon[y][x+1] > 0)
        doors.insert(doors.cend(), 1);
    if(y+1 < dungeonSize-1 && dungeon[y+1][x] > 0)
        doors.insert(doors.cend(), 2);
    if(x+1 < dungeonSize-1 && dungeon[y][x-1] > 0)
        doors.insert(doors.cend(), 3);
    return doors;
}

int DungeonManager::RandomInt(int min, int max) {
    max++;
   // x is in [0,1[
   double x = rand()/static_cast<double>(RAND_MAX+1);

   // [0,1[ * (max - min) + min is in [min,max[
   int that = min + static_cast<int>( x * (max - min) );

   return that;
}

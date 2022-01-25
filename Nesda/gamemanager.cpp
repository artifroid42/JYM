#include "gamemanager.h"
#include "charactercontroller.h"


#include "vector"
using namespace std;

GameManager::GameManager()
{
    player.x = 10;
    enemy.x = 5;


}

void GameManager::BoucleDeJeu()
{
    cout << "player : " << player.x << endl;
    cout << "enemy : " << enemy.x << endl;
}


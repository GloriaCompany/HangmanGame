#include <iostream>
#include <deque>
#include "Player.h"
#include "Game.h"

using namespace std;

int main()
{
    string name;
    deque<Player> players;
    Player player;
    
    cout << "Input name: ";
    cin >> name;

    player.Auth(name);

    system("pause");
    return 0;
}
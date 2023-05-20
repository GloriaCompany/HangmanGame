#include <iostream>
#include <deque>
#include "Player.h"
#include "Game.h"

using namespace std;

int main()
{
    string name_;
    deque<Player> players;
    Player player;
    
    cout << "Input name: ";
    cin >> name_;

    player.Auth(name_);

    system("pause");
    return 0;
}
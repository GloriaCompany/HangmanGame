#include <iostream>
#include <deque>
#include "Player.h"
#include "Game.h"
#include "windows.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string name, name1;
    Game Check;
    deque<Player> players;
    Player player;


    cout << "Input name for player 1: ";
    cin >> name;
    while (Check.ValidateNickname(name) != true)
    {
        cout << "Input name for player 1: ";
        cin >> name; 
    }
    player.Auth(name);
    system("cls");


    cout << "Input name for player 2: ";
    cin >> name1;
    while (Check.ValidateNickname(name1) != true)
    {
        cout << "Input name for player 2: ";
        cin >> name1;
    }
    player.Auth(name1);
    system("cls");
    
     



    system("pause");
    return 0;
}
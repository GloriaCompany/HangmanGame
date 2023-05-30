#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "Player.h"
#include "Game.h"
#include "windows.h"

#define WORDS_FILE_PATH "words.txt"

using namespace std;

int main()
{
    wstring name = L"";
    char letter;
    string word;
    Game game;
    Player player1;
    Player player2;

    _setmode(_fileno(stdout), _O_WTEXT);

    wcout << "Input name for player 1: ";
    wcin >> name;
    player1.setName(name);
    system("cls");

    wcout << "Input name for player 2: ";
    wcin >> name;
    player2.setName(name);
    system("cls");

    word = game.GenerateWord(WORDS_FILE_PATH);

    for (int i = 0; i < game.GetNumOfLettersInWord(word); i++)
    {
        cout << "Letter: ";
        cin >> letter;
        game.CheckLetterInWord(word, letter);
    }

    system("pause");
    return 0;
}
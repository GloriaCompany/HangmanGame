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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Game game;
    Player firstPlayer, secondPlayer;

    string playerNickName, generatedWord;
    int userInput = 0;
    char letter;

    do {
        cout << "Меню\n1. Нова гра\n2. Вихід\nОберіть дію: ";
        cin >> userInput;
        if (cin.fail() || userInput < 1 || userInput > 2) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "ERROR: Помилка вводу. Повторіть спробу, будь-ласка.\n";
        }
    } while (cin.fail() || userInput < 1 || userInput > 2);

    system("cls");

    switch (userInput) {
    case 1:
        do {
            cout << "Введіть ім'я першого гравця: ";
            cin >> playerNickName;
            if (!game.ValidateNickname(playerNickName)) cout << "ERROR: Помилка введення нікнейму. Правила введення:\n1. Не менше 8 та не більше 15 символів"
                "\n2. Не містить пробілів та наступних символів: " << game.getInvalidSymbols() << "\nПовторіть спробу, будь-ласка.\n";
        } while (!game.ValidateNickname(playerNickName));
        firstPlayer.setName(playerNickName);

        playerNickName = "";

        do {
            cout << "Введіть ім'я другого гравця: ";
            cin >> playerNickName;
            if (!game.ValidateNickname(playerNickName)) cout << "ERROR: Помилка введення нікнейму. Правила введення:\n1. Не менше 8 та не більше 15 символів"
                "\n2. Не містить пробілів та наступних символів: " << game.getInvalidSymbols() << "\nПовторіть спробу, будь-ласка.\n";
        } while (!game.ValidateNickname(playerNickName));
        secondPlayer.setName(playerNickName);

        system("cls");

        cout << "Дані гравців:\n";
        cout << "Перший гравець\n";
        cout << "Ім'я: " << firstPlayer.getName();
        cout << "\nПерший гравець\n";
        cout << "Ім'я: " << secondPlayer.getName();

        system("pause");
        break;
    case 2:
        return 0;
        break;
    }

    system("cls");

    generatedWord = game.GenerateWord("words.txt");
    cout << generatedWord << '\n';

    cout << game.GetPartOfWord(generatedWord, 0, 3) << '\n';
    cout << game.GetNumOfLettersInWord(generatedWord) << '\n';
    cout << "Letter: ";
    cin >> letter;
    game.CheckLetterInWord(generatedWord, letter);

    system("pause");
    return 0;
}
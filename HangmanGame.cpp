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
    DesignHangman dh;
    Player firstPlayer, secondPlayer;

    string playerNickName, generatedWord;
    int userInput = 0, position, count;
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

            if (firstPlayer.getName() == secondPlayer.getName()) {
                cout << "ERROR: Імена гравців не мають співпадати. Повторіть спробу, будь-ласка.\n";
            }
        } while (firstPlayer.getName() == secondPlayer.getName());

        system("cls");

        cout << "Дані гравців:\n";
        cout << "Перший гравець\n";
        cout << "Ім'я: " << firstPlayer.getName() << '\n';
        cout << "Статус шибениці:\n";
        dh.HangmanStageStart();
        cout << endl;
        cout << "\nДругий гравець\n";
        cout << "Ім'я: " << secondPlayer.getName() << '\n';
        cout << "Статус шибениці:\n";
        dh.HangmanStageStart();
        cout << endl;
        break;
    case 2:
        return 0;
        break;
    }

    system("pause");
    system("cls");

    generatedWord = game.GenerateWord("words.txt");
    cout << generatedWord;

    std::string guessedWord(generatedWord.length(), '_');

    while (true) {
        std::cout << "Черга гравця " << firstPlayer.getName() << '\n';
        std::cout << "Введіть літеру: ";
        std::cin >> letter;
        game.CheckLetterInWord(firstPlayer, generatedWord, guessedWord, letter);
        std::cout << "\nВідгадане слово: " << guessedWord << std::endl;
        std::cout << std::endl;

        system("pause");
        system("cls");

        if (game.IsAllLettersGuessed(generatedWord, guessedWord)) {
            std::cout << "Всі букви вгадані! Гра закінчена." << std::endl;
            std::cout << "Переможець: " << firstPlayer.getName() << std::endl;
            break;
        }

        if (firstPlayer.getAttempts() <= 0) {
            std::cout << "Переможець: " << secondPlayer.getName() << std::endl;
            break;
        }

        std::cout << "Черга гравця " << secondPlayer.getName() << '\n';
        std::cout << "Введіть літеру: ";
        std::cin >> letter;
        game.CheckLetterInWord(secondPlayer, generatedWord, guessedWord, letter);
        std::cout << "\nВідгадане слово: " << guessedWord << std::endl;
        std::cout << std::endl;

        system("pause");
        system("cls");

        if (game.IsAllLettersGuessed(generatedWord, guessedWord)) {
            std::cout << "Всі букви вгадані! Гра закінчена." << std::endl;
            std::cout << "Переможець: " << secondPlayer.getName() << std::endl;
            break;
        }

        if (secondPlayer.getAttempts() <= 0) {
            std::cout << "Переможець: " << firstPlayer.getName() << std::endl;
            break;
        }

        if (firstPlayer.getAttempts() <= 0 && secondPlayer.getAttempts() <= 0) {
            std::cout << "Нічия! Обидва гравці використали всі спроби." << std::endl;
            break;
        }

        if (firstPlayer.getAttempts() == 1 || secondPlayer.getAttempts() == 1) {
            std::cout << "Ви можете отримати частину слова. Чи бажаєте ви це зробити?\n1. Так\n2. Ні\nВаш вибір: ";
            userInput = 0;
            cin >> userInput;

            switch (userInput)
            {
            case 1:
                cout << "Введіть позицію у слові: ";
                cin >> position;
                cout << "Введіть кількість літер: ";
                cin >> count;
                cout << "Отримана частина: " << game.GetPartOfWord(generatedWord, position, count) << '\n';
                system("pause");
                break;
            case 2:
                system("cls");
                continue;
                break;
            }
        }
    }

    system("pause");
    return 0;
}
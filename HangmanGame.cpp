#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <codecvt>
#include "Player.h"
#include "Game.h"

#define WORDS_FILE_PATH "words.txt"

using namespace std;

int main()
{
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stdin), _O_WTEXT);

    Game game;
    DesignHangman dh;
    Player firstPlayer, secondPlayer;

    wstring playerNickName, generatedWord;
    int userInput = 0, position, count;
    wchar_t letter;

    bool inMainMenu = true;

    while (inMainMenu) {
        do {
            wcout << L"Меню\n1. Нова гра\n2. Вихід\nОберіть дію: ";
            wcin >> userInput;
            if (wcin.fail() || userInput < 1 || userInput > 2) {
                system("cls");
                wcin.clear();
                wcin.ignore(numeric_limits<streamsize>::max(), '\n');
                wcout << RED << L"ERROR: Помилка вводу. Повторіть спробу, будь-ласка.\n" << WHT;
            }
        } while (wcin.fail() || userInput < 1 || userInput > 2);

        system("cls");

        switch (userInput) {
        case 1:
            do {
                do {
                    wcout << L"Введіть ім'я першого гравця: ";
                    wcin >> playerNickName;
                    if (!game.ValidateNickname(playerNickName)) {
                        //system("cls");
                        wcout << RED 
                              << L"ERROR: Помилка введення нікнейму. Правила введення: "
                              << GRN
                              << L"\n1.Не менше 8 та не більше 15 символів"
                              << L"\n2. Не містить пробілів та наступних символів: " << game.getInvalidSymbols()
                              << RED
                              << L"\nПовторіть спробу, будь-ласка.\n" 
                              << WHT;
                    }
                } while (!game.ValidateNickname(playerNickName));
                firstPlayer.setName(playerNickName);

                playerNickName = L"";

                do {
                    wcout << L"Введіть ім'я другого гравця: ";
                    wcin >> playerNickName;
                    if (!game.ValidateNickname(playerNickName)) {
                        //system("cls");
                        wcout << RED 
                              << L"ERROR: Помилка введення нікнейму. Правила введення: "
                              << GRN
                              << L"\n1. Не менше 8 та не більше 15 символів"
                              << L"\n2. Не містить пробілів та наступних символів: " << game.getInvalidSymbols()
                              << RED
                              << L"\nПовторіть спробу, будь-ласка.\n"
                              << WHT;
                    }
                } while (!game.ValidateNickname(playerNickName));
                secondPlayer.setName(playerNickName);

                if (firstPlayer.getName() == secondPlayer.getName()) {
                    system("cls");
                    wcout << RED << L"ERROR: Імена гравців не мають співпадати. Повторіть спробу, будь-ласка.\n" << WHT;
                }
            } while (firstPlayer.getName() == secondPlayer.getName());

            system("cls");

            wcout << L"Дані гравців:\n";
            wcout << L"Перший гравець\n";
            wcout << L"Ім'я: " << firstPlayer.getName() << L'\n';
            wcout << L"Статус шибениці:\n";
            dh.HangmanStageStart();
            wcout << endl;
            wcout << L"\nДругий гравець\n";
            wcout << L"Ім'я: " << secondPlayer.getName() << L'\n';
            wcout << L"Статус шибениці:\n";
            dh.HangmanStageStart();
            wcout << endl;
            break;
        case 2:
            inMainMenu = false;
            break;
        }

        system("pause");
        system("cls");

        if (!inMainMenu) {
            continue;
        }

        generatedWord = game.GenerateWord(L"words.txt");
        std::wstring guessedWord(generatedWord.length(), L'_');

        while (true) {
            std::wcout << L"Черга гравця " << firstPlayer.getName() << L'\n';
            std::wcout << L"Введіть літеру: ";
            std::wcin >> letter;
            game.CheckLetterInWord(firstPlayer, generatedWord, guessedWord, letter);
            std::wcout << L"\nВідгадане слово: " << guessedWord << std::endl;
            std::wcout << std::endl;

            system("pause");
            system("cls");

            if (game.IsAllLettersGuessed(generatedWord, guessedWord)) {
                std::wcout << L"Всі букви вгадані! Гра закінчена." << std::endl;
                std::wcout << L"Переможець: " << firstPlayer.getName() << std::endl;
                break;
            }

            if (firstPlayer.getAttempts() <= 0) {
                std::wcout << L"Переможець: " << secondPlayer.getName() << std::endl;
                break;
            }

            std::wcout << L"Черга гравця " << secondPlayer.getName() << L'\n';
            std::wcout << L"Введіть літеру: ";
            std::wcin >> letter;
            game.CheckLetterInWord(secondPlayer, generatedWord, guessedWord, letter);
            std::wcout << L"\nВідгадане слово: " << guessedWord << std::endl;
            std::wcout << std::endl;

            system("pause");
            system("cls");

            if (game.IsAllLettersGuessed(generatedWord, guessedWord)) {
                std::wcout << L"Всі букви вгадані! Гра закінчена." << std::endl;
                std::wcout << L"Переможець: " << secondPlayer.getName() << std::endl;
                break;
            }

            if (secondPlayer.getAttempts() <= 0) {
                std::wcout << L"Переможець: " << firstPlayer.getName() << std::endl;
                break;
            }

            if (firstPlayer.getAttempts() <= 0 && secondPlayer.getAttempts() <= 0) {
                std::wcout << L"Нічия! Обидва гравці використали всі спроби." << std::endl;
                break;
            }

            if (firstPlayer.getAttempts() == 1 || secondPlayer.getAttempts() == 1) {
                std::wcout << L"Ви можете отримати частину слова. Чи бажаєте ви це зробити?\n1. Так\n2. Ні\nВаш вибір: ";
                userInput = 0;
                wcin >> userInput;

                switch (userInput)
                {
                case 1:
                    wcout << L"Введіть позицію у слові: ";
                    wcin >> position;
                    wcout << L"Введіть кількість літер: ";
                    wcin >> count;
                    wcout << L"Отримана частина: " << game.GetPartOfWord(generatedWord, position, count) << L'\n';
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    continue;
                    break;
                }
            }
        }

        system("pause");
        system("cls");
    }

    return 0;
}
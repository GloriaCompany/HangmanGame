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
	Player firstPlayer, secondPlayer;

	wstring playerNickName, generatedWord;
	int userInput = 0, position, count;
	wchar_t letter;

	bool inMainMenu = true, flag = true;

	while (inMainMenu) {
		do {
			wcout
				<< WHT
				<< L"╭──────────────────────────────────╮\n"
				<< L"│" << RED << L"              Меню                " << WHT << L"│\n"
				<< L"├──────────────────────────────────┤\n"
				<< L"│" << CYN << L" 1. " << GRN << L"Нова гра                      " << WHT << L"│\n"
				<< L"│" << CYN << L" 2. " << GRN << L"Вихід                         " << WHT << L"│\n"
				<< L"╰──────────────────────────────────╯\n"
				<< L" Оберіть опцію (1 - 2): " << CYN;
			wcin >> userInput;
			if (wcin.fail() || userInput < 1 || userInput > 2) {
				system("cls");
				wcin.clear();
				wcin.ignore(numeric_limits<streamsize>::max(), '\n');
				wcout
					<< WHT
					<< L"╭──────────────────────────────────╮\n"
					<< L"│" << RED << L"       ERROR: Помилка вводу" << WHT << L"       │\n"
					<< L"├──────────────────────────────────┤\n"
					<< L"│" << MAG << L"   Повторіть спробу, будь-ласка" << WHT << L"   │\n"
					<< L"╰──────────────────────────────────╯\n";
			}
		} while (wcin.fail() || userInput < 1 || userInput > 2);

		system("cls");

		switch (userInput) {
		case 1:
			flag = true;
			do {
				playerNickName = L"";

				do {
					wcout << WHT << L" Введіть ім'я першого гравця: " << CYN;
					wcin >> playerNickName;
					if (!game.ValidateNickname(playerNickName)) {
						system("cls");
						wcout << WHT
							<< L"╭───────────────────────────────────────────────╮\n"
							<< L"│" << RED << L"\tERROR: Помилка введення нікнейму\t" << WHT << L"│\n"
							<< L"├───────────────────────────────────────────────┤\n"
							<< L"│" << CYN << L" 1. " << GRN << L"Не менше 5 та не більше 15 символів" << WHT << L"\t│\n"
							<< L"│" << CYN << L" 2. " << GRN << L"Не містить пробілів та наступних символів:" << WHT << L"\t│\n"
							<< L"│" << CYN << L"\t" << game.getInvalidSymbols() << WHT << L"\t\t│\n"
							<< L"├───────────────────────────────────────────────┤\n"
							<< L"│" << MAG << L"\tПовторіть спробу, будь-ласка" << WHT << L"\t\t│\n"
							<< L"╰───────────────────────────────────────────────╯\n";
					}
				} while (!game.ValidateNickname(playerNickName));
				firstPlayer.setName(playerNickName);

				playerNickName = L"";

				do {
					wcout << WHT << L" Введіть ім'я другого гравця: " << CYN;
					wcin >> playerNickName;
					if (!game.ValidateNickname(playerNickName)) {
						system("cls");
						wcout << WHT
							<< L"╭───────────────────────────────────────────────╮\n"
							<< L"│" << RED << L"\tERROR: Помилка введення нікнейму\t" << WHT << L"│\n"
							<< L"├───────────────────────────────────────────────┤\n"
							<< L"│" << CYN << L" 1. " << GRN << L"Не менше 8 та не більше 15 символів" << WHT << L"\t│\n"
							<< L"│" << CYN << L" 2. " << GRN << L"Не містить пробілів та наступних символів:" << WHT << L"\t│\n"
							<< L"│" << CYN << L"\t" << game.getInvalidSymbols() << WHT << L"\t\t│\n"
							<< L"├───────────────────────────────────────────────┤\n"
							<< L"│" << MAG << L"\tПовторіть спробу, будь-ласка." << WHT << L"\t\t│\n"
							<< L"╰───────────────────────────────────────────────╯\n";
					}
				} while (!game.ValidateNickname(playerNickName));
				secondPlayer.setName(playerNickName);

				if (firstPlayer.getName() == secondPlayer.getName()) {
					system("cls");
					wcout
						<< WHT
						<< L"╭───────────────────────────────────────────────────────────╮\n"
						<< L"│" << RED << L"ERROR: Імена гравців співпадають. Повторіть спробу, будь-ласка.\t" << WHT << L"│\n"
						<< L"╰───────────────────────────────────────────────────────────╯\n";
				}
			} while (firstPlayer.getName() == secondPlayer.getName());

			firstPlayer.setAttempts(8);
			secondPlayer.setAttempts(8);

			system("cls");
			wcout
				<< WHT
				<< L"╭──────────────────────────────────╮\n"
				<< L"│" << GRN << L"          Дані гравців            " << WHT << L"│\n"
				<< L"├──────────────────────────────────┤\n"
				<< L"│" << CYN << L" Гравець 1: " << MAG << firstPlayer.getName() << "             " << WHT << L"│\n"
				<< L"│" << CYN << L" Гравець 2: " << MAG << secondPlayer.getName() << "             " << WHT << L"│\n"
				<< L"╰──────────────────────────────────╯\n";
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
		wstring guessedWord(generatedWord.length(), L'_');

		while (true) {
			wcout
				<< WHT
				<< L"╭──────────────────────────────────╮\n"
				<< L"│" << GRN << L"     Черга гравця: " << CYN << firstPlayer.getName() << "      " << WHT << L"│\n"
				<< L"╰──────────────────────────────────╯\n"
				<< L" Введіть літеру: " << CYN;
			wcin >> letter;
			game.CheckLetterInWord(firstPlayer, generatedWord, guessedWord, letter);
			wcout << L"\n Відгадане слово: " << guessedWord << endl;
			wcout << endl;

			system("pause");
			system("cls");

			if (game.IsAllLettersGuessed(generatedWord, guessedWord)) {
				wcout
					<< WHT
					<< L"╭────────────────────────────────────────────╮\n"
					<< L"│" << GRN << L"       Всі букви вгадані! Гра закінчена      " << WHT << L"│\n"
					<< L"├────────────────────────────────────────────┤\n"
					<< L"│" << GRN << L" Переможець: " << YEL << firstPlayer.getName() << "                      " << WHT << L"│\n"
					<< L"│" << GRN << L" Програвший: " << RED << secondPlayer.getName() << "                      " << WHT << L"│\n"
					<< L"│" << GRN << L" Загадане слово: " << MAG << generatedWord << "                      " << WHT << L"│\n"
					<< L"╰────────────────────────────────────────────╯\n";
				system("pause");
				break;
			}

			if (firstPlayer.getAttempts() <= 0) {
				wcout
					<< WHT
					<< L"╭────────────────────────────────────────────╮\n"
					<< L"│" << GRN << L"                  Гра закінчена             " << WHT << L"│\n"
					<< L"├────────────────────────────────────────────┤\n"
					<< L"│" << GRN << L" Переможець: " << YEL << secondPlayer.getName() << "                      " << WHT << L"│\n"
					<< L"│" << GRN << L" Програвший: " << RED << firstPlayer.getName() << "                      " << WHT << L"│\n"
					<< L"│" << GRN << L" Загадане слово: " << MAG << generatedWord << "                      " << WHT << L"│\n"
					<< L"╰────────────────────────────────────────────╯\n";
				system("pause");
				break;
			}

			wcout
				<< WHT
				<< L"╭──────────────────────────────────╮\n"
				<< L"│" << GRN << L"     Черга гравця: " << CYN << secondPlayer.getName() << "      " << WHT << L"│\n"
				<< L"╰──────────────────────────────────╯\n"
				<< L" Введіть літеру: " << CYN;
			wcin >> letter;
			game.CheckLetterInWord(secondPlayer, generatedWord, guessedWord, letter);
			wcout << L"\n Відгадане слово: " << guessedWord << endl;
			wcout << endl;

			system("pause");
			system("cls");

			if (game.IsAllLettersGuessed(generatedWord, guessedWord)) {
				wcout
					<< WHT
					<< L"╭────────────────────────────────────────────╮\n"
					<< L"│" << GRN << L"     Всі букви вгадані! Гра закінчена       " << WHT << L"│\n"
					<< L"├────────────────────────────────────────────┤\n"
					<< L"│" << GRN << L" Переможець: " << YEL << secondPlayer.getName() << "                      " << WHT << L"│\n"
					<< L"│" << GRN << L" Програвший: " << RED << firstPlayer.getName() << "                      " << WHT << L"│\n"
					<< L"│" << GRN << L" Загадане слово: " << MAG << generatedWord << "                      " << WHT << L"│\n"
					<< L"╰────────────────────────────────────────────╯\n";
				system("pause");
				break;
			}

			if (secondPlayer.getAttempts() <= 0) {
				wcout
					<< WHT
					<< L"╭────────────────────────────────────────────╮\n"
					<< L"│" << GRN << L"                  Гра закінчена                  " << WHT << L"│\n"
					<< L"├────────────────────────────────────────────┤\n"
					<< L"│" << GRN << L" Переможець: " << YEL << firstPlayer.getName() << "                      " << WHT << L"│\n"
					<< L"│" << GRN << L" Програвший: " << RED << secondPlayer.getName() << "                      " << WHT << L"│\n"
					<< L"│" << GRN << L" Загадане слово: " << MAG << generatedWord << "                      " << WHT << L"│\n"
					<< L"╰────────────────────────────────────────────╯\n";
				system("pause");
				break;
			}

			if (firstPlayer.getAttempts() == 1 || secondPlayer.getAttempts() == 1) {
				if (flag) {
					do {
						wcout
							<< WHT
							<< L"╭────────────────────────────────────────────╮\n"
							<< L"│" << GRN << L"      Ви бажаєте отримати частину слова?    " << WHT << L"│\n"
							<< L"├────────────────────────────────────────────┤\n"
							<< L"│" << CYN << L" 1. " << GRN << L"Так                                     " << WHT << L"│\n"
							<< L"│" << CYN << L" 2. " << GRN << L"Ні                                      " << WHT << L"│\n"
							<< L"╰────────────────────────────────────────────╯\n"
							<< L" Ваш вибір: " << CYN;
						userInput = 0;
						wcin >> userInput;
						if (wcin.fail() || userInput < 1 || userInput > 2) {
							system("cls");
							wcin.clear();
							wcin.ignore(numeric_limits<streamsize>::max(), '\n');
							wcout
								<< WHT
								<< L"╭──────────────────────────────────╮\n"
								<< L"│" << RED << L"       ERROR: Помилка вводу" << WHT << L"       │\n"
								<< L"├──────────────────────────────────┤\n"
								<< L"│" << MAG << L"   Повторіть спробу, будь-ласка" << WHT << L"   │\n"
								<< L"╰──────────────────────────────────╯\n";
						}
					} while (wcin.fail() || userInput < 1 || userInput > 2);

					system("cls");

					switch (userInput)
					{
					case 1:
						do {
							wcout << WHT << L" Введіть позицію у слові (0 - " << generatedWord.size() << "): " << CYN;
							wcin >> position;
							if (wcin.fail() || position < 0 || position > generatedWord.size() - 1) {
								system("cls");
								wcin.clear();
								wcin.ignore(numeric_limits<streamsize>::max(), '\n');
								wcout
									<< WHT
									<< L"╭──────────────────────────────────╮\n"
									<< L"│" << RED << L"       ERROR: Помилка вводу" << WHT << L"       │\n"
									<< L"├──────────────────────────────────┤\n"
									<< L"│" << MAG << L"   Повторіть спробу, будь-ласка" << WHT << L"   │\n"
									<< L"╰──────────────────────────────────╯\n";
							}
						} while (wcin.fail() || position < 0 || position > generatedWord.size() - 1);

						do {
							wcout << WHT << L" Введіть кількість літер (" << position << " - " << generatedWord.size() << "): " << CYN;
							wcin >> count;
							if (wcin.fail() || count < 1 || count > generatedWord.size() - position) {
								system("cls");
								wcin.clear();
								wcin.ignore(numeric_limits<streamsize>::max(), '\n');
								wcout
									<< WHT
									<< L"╭──────────────────────────────────╮\n"
									<< L"│" << RED << L"       ERROR: Помилка вводу" << WHT << L"       │\n"
									<< L"├──────────────────────────────────┤\n"
									<< L"│" << MAG << L"   Повторіть спробу, будь-ласка" << WHT << L"   │\n"
									<< L"╰──────────────────────────────────╯\n";
							}
						} while (wcin.fail() || count < 1 || count > generatedWord.size() - position);

						wcout << WHT << L" Отримана частина: " << CYN << game.GetPartOfWord(generatedWord, position, count) << WHT << L'\n';
						system("pause");
						system("cls");
						break;
					case 2:
						system("cls");
						continue;
						break;
					}

					flag = false;
				}
			}
		}
		system("cls");
	}

	return 0;
}
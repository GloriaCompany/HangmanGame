#include "Game.h"

// Масив символів, що повинні валідуватися
const std::string invalidSymbols = "!@./[]()$%^&*:;`<>,-+№?";

Game::Game() {}

std::string Game::getInvalidSymbols() { return invalidSymbols; }

bool Game::ValidateNickname(const std::string& nickname)
{
    for (char symbol : invalidSymbols)
        if (nickname.find(symbol) != std::string::npos)
            return false;

    if (nickname.find(' ') != std::string::npos) return false;
    else if (nickname.size() < this->NICKNAME_MIN_LENGTH || nickname.size() > this->NICKNAME_MAX_LENGTH) return false;
    
    return true;
}

std::string Game::GenerateWord(const std::string filePath)
{
    std::ifstream file(filePath);
    std::vector<std::string> words;
    std::string word;

    if (file.is_open()) {
        while (std::getline(file, word)) {
            words.push_back(word);
        }

        file.close();

        if (!words.empty()) {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            int randomIndex = std::rand() % words.size();
            return words[randomIndex];
        }
    } else {
        std::cout << "ERROR: Помилка відкриттся файлу. Перевірте стан бази зі словами та повторіть спробу.\n";
        return "";
    }

    return "";
}

std::string Game::GetPartOfWord(const std::string& word, int position, int lettersCount)
{
    if (position < 0 || position >= static_cast<int>(word.length())) {
        throw std::out_of_range("ERROR: Позиція не має бути за межами заданого слова.\n");
    } else if (lettersCount < 0 || lettersCount > static_cast<int>(word.length()) - position) {
        throw std::out_of_range("ERROR: Кількість зчитуваних літер не має бути за межами заданого слова.\n");
    }

    return word.substr(position, lettersCount);
}

void Game::CheckLetterInWord(const std::string& word, char firstLetter)
{
    DesignHangman dh;
    char letter = firstLetter;

    for (int i = 0; i < 8; i++) {
        if (word.find(letter) != std::string::npos) {
            std::cout << "Вітаємо! Ви вгадали літеру!\n";
            std::cout << "Введіть нову літеру: ";
            std::cin >> letter;
        } else {
            switch (i) {
                case 0: dh.HangmanStageOne(); break;
                case 1: dh.HangmanStageTwo(); break;
                case 2: dh.HangmanStageThree(); break;
                case 3: dh.HangmanStageFour(); break;
                case 4: dh.HangmanStageFive(); break;
                case 5: dh.HangmanStageSix(); break;
                case 6: dh.HangmanStageSeven(); break;
                case 7: GameOver(word); return;
            }
            std::cout << "Введіть літеру: ";
            std::cin >> letter;
        }
    }
}

int Game::GetNumOfLettersInWord(const std::string& word)
{
	return (int)word.length();
}

void Game::GameOver(const std::string& word)
{
    DesignHangman dh;
    std::cout << L"Гру закінчено. Загадане слово: " << word << std::endl;
    dh.HangmanStageEight();
}

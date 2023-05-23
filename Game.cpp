#include "Game.h"
#include "DesignHangman.h"

// Масив символів, що повинні валідуватися
const std::array<char, 25> invalidSymbols = { '!','@','.','/','[',']','(',')','$','%','^','&','*',':',';','"','`','<','>',',','-','+','№','?' };

Game::Game() {}

bool Game::ValidateNickname(const std::string& nickName)
{
    if (nickName.find(' ') != std::string::npos) {
        std::cout << "ERROR: Ім'я гравця містить заборонені символи. Повторіть введення нікнейму.\n"; 
        return false;
    } else if (nickName.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
        std::cout << "ERROR: Ім'я гравця містить заборонені символи. Повторіть введення нікнейму.\n"; 
        return false;
    } else if (nickName.size() < this->NICKNAME_MIN_LENGTH || nickName.size() > this->NICKNAME_MAX_LENGTH) {
        std::cout << "ERROR: Мінімальна довжина нікнейму - " << this->NICKNAME_MIN_LENGTH << ", максимальна довжина нікнейму - " << NICKNAME_MAX_LENGTH << ". Повторіть введення нікнейму.\n"; 
        return false;
    } else return true;
}

std::string Game::GenerateWord(const std::string& filePath)
{
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cout << "ERROR: Помилка відкриття файлу зі словами. Перевірте шлях до фалу та повторіть спробу.\n";
        return "";
    } else if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "ERROR: Наразі файл зі словами пустий. Заповність файл словами та повторіть спробу.\n";
        return "";
    }

    int lineCount = 0;
    std::string line;
    while (std::getline(file, line))
        ++lineCount;

    std::srand((unsigned int)std::time(nullptr));
    const int lineNumber = std::rand() % lineCount + 1;

    file.clear();
    file.seekg(0, std::ios::beg);
    for (int i = 1; i <= lineNumber; ++i)
        std::getline(file, line);

    if (line.find(' ') != std::string::npos) {
        std::cout << "ERROR: Слово містить заборонені символи. Перевірте правильність введеного слова та повторіть спробу.\n";
        return "";
    } else if (std::any_of(line.begin(), line.end(), ::isdigit)) {
        std::cout << "ERROR: Слово містить заборонені символи. Перевірте правильність введеного слова та повторіть спробу.\n";
        return "";
    } else if (line.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
        std::cout << "ERROR: Слово містить заборонені символи. Перевірте правильність введеного слова та повторіть спробу.\n";
        return "";
    }

    return line;
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

bool Game::CheckLetterInWord(const std::string& word, char letter)
{
    DesignHangman dh;
    bool found = false;
    int attempts = 0;
    std::string result(word.length(), '_');

    while (!found && attempts < 8) {
        bool letterFound = false;

        for (int i = 0; i < word.length(); ++i) {
            if (word.at(i) == letter) {
                result.at(i) = letter;
                letterFound = true;
            }
        }

        if (letterFound) {
            std::cout << "Ви вгадали літеру.\n";
            std::cout << result << std::endl;
        } else {
            ++attempts;
            std::cout << "Ви не вгадали літеру. У вас залишилось " << 8 - attempts << " спроб.\n";
            std::cout << "Шибениця на теперішній стан:\n";

            switch (attempts) {
            case 1:
                dh.HangmanStageOne();
                break;
            case 2:
                dh.HangmanStageTwo();
                break;
            case 3:
                dh.HangmanStageThree();
                break;
            case 4:
                dh.HangmanStageFour();
                break;
            case 5:
                dh.HangmanStageFive();
                break;
            case 6:
                dh.HangmanStageSix();
                break;
            case 7:
                dh.HangmanStageSeven();
                break;
            case 8:
                dh.HangmanStageEight();
                break;
            default:
                std::cout << result << std::endl;
                break;
            }
        }

        if (result == word) {
            std::cout << "Вітаємо, ви вгадали усе слово!";
            found = true;
        }
    }
    return found;
}

int Game::GetNumOfLettersInWord(const std::string& word)
{
	return (int)word.length();
}

void Game::GameOver(const std::string& word)
{
    DesignHangman dh;
    std::cout << "Гру закінчено. Загадане слово: " << word << std::endl;
    dh.HangmanStageEight();
}

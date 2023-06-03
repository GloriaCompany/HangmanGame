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

bool Game::IsAllLettersGuessed(const std::string& word, const std::string& guessedWord) {
    return (guessedWord.find('_') == std::string::npos);
}

void Game::CheckLetterInWord(Player& player, const std::string& word, std::string& guessedWord, char letter)
{
    DesignHangman dh;

    if (word.find(letter) != std::string::npos) {
        std::cout << "Вітаємо! Ви вгадали літеру!\n";

        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] == letter) {
                guessedWord[i] = letter;
            }
        }
    }
    else {
        player.decrementAttempts();

        switch (player.getAttempts()) {
        case 7:
            dh.HangmanStageOne();
            break;
        case 6:
            dh.HangmanStageTwo();
            break;
        case 5:
            dh.HangmanStageThree();
            break;
        case 4:
            dh.HangmanStageFour();
            break;
        case 3:
            dh.HangmanStageFive();
            break;
        case 2:
            dh.HangmanStageSix();
            break;
        case 1:
            dh.HangmanStageSeven();
            break;
        case 0:
            dh.HangmanStageEight();
            break;
        }
    }
}

void Game::GameOver(Player& firstPlayer, Player& secondPlayer, const std::string& word)
{
    DesignHangman dh;
    std::cout << "Game Over\n";
    std::cout << "Статус шибениць:\n";

    std::cout << "Гравець " << firstPlayer.getName() << '\n';
    switch (firstPlayer.getAttempts()) {
        case 8: dh.HangmanStageEight(); break;
        case 7: dh.HangmanStageOne(); break;
        case 6: dh.HangmanStageTwo(); break;
        case 5: dh.HangmanStageThree(); break;
        case 4: dh.HangmanStageFour(); break;
        case 3: dh.HangmanStageFive(); break;
        case 2: dh.HangmanStageSix(); break;
        case 1: dh.HangmanStageSeven(); break;
        case 0: dh.HangmanStageEight(); break;
    }

    std::cout << "Гравець " << secondPlayer.getName() << '\n';
    switch (secondPlayer.getAttempts()) {
        case 8: dh.HangmanStageEight(); break;
        case 7: dh.HangmanStageOne(); break;
        case 6: dh.HangmanStageTwo(); break;
        case 5: dh.HangmanStageThree(); break;
        case 4: dh.HangmanStageFour(); break;
        case 3: dh.HangmanStageFive(); break;
        case 2: dh.HangmanStageSix(); break;
        case 1: dh.HangmanStageSeven(); break;
        case 0: dh.HangmanStageEight(); break;
    }

    system("pause");
}

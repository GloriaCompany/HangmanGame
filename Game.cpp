#include "Game.h"

// Масив символів, що повинні валідуватися
const std::wstring invalidSymbols = L"!@./[]()$%^&*:;`<>,-+№?";

Game::Game() {}

std::wstring Game::getInvalidSymbols() { return invalidSymbols; }

bool Game::ValidateNickname(const std::wstring& nickname)
{
    for (wchar_t symbol : invalidSymbols)
        if (nickname.find(symbol) != std::wstring::npos)
            return false;

    if (nickname.find(L" ") != std::wstring::npos) return false;
    else if (nickname.size() < this->NICKNAME_MIN_LENGTH || nickname.size() > this->NICKNAME_MAX_LENGTH) return false;
    
    return true;
}

std::wstring Game::GenerateWord(const std::wstring filePath)
{
    std::wifstream file(filePath);
    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));

    std::vector<std::wstring> words;
    std::wstring word;

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
    }
    else {
        std::wcout << RED << L"ERROR: Помилка відкриття файлу. Перевірте стан бази зі словами та повторіть спробу.\n" << WHT;
    }

    return L"";
}

std::wstring Game::GetPartOfWord(const std::wstring& word, int position, int lettersCount)
{
    if (position < 0 || position >= static_cast<int>(word.length())) {
        std::wcout << L"ERROR: Позиція не має бути за межами заданого слова.\n";
    } else if (lettersCount < 0 || lettersCount > static_cast<int>(word.length()) - position) {
        std::wcout << L"ERROR: Кількість зчитуваних літер не має бути за межами заданого слова.\n";
    }

    return word.substr(position, lettersCount);
}

bool Game::IsAllLettersGuessed(const std::wstring& word, const std::wstring& guessedWord) {
    return (guessedWord.find(L"_") == std::wstring::npos);
}

void Game::CheckLetterInWord(Player& player, const std::wstring& word, std::wstring& guessedWord, wchar_t letter)
{
    DesignHangman dh;

    if (word.find(letter) != std::wstring::npos) {
        std::wcout << YEL <<L" Вітаємо! Ви вгадали літеру!\n" << WHT;

        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] == letter) {
                guessedWord[i] = letter;
            }
        }
    }
    else {
        player.decrementAttempts();

        switch (player.getAttempts()) {
        case 7: dh.HangmanStageOne(); break;
        case 6: dh.HangmanStageTwo(); break;
        case 5: dh.HangmanStageThree(); break;
        case 4: dh.HangmanStageFour(); break;
        case 3: dh.HangmanStageFive(); break;
        case 2: dh.HangmanStageSix(); break;
        case 1: dh.HangmanStageSeven(); break;
        case 0: dh.HangmanStageEight(); break;
        }
    }
}
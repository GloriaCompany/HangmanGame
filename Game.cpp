#include "Game.h"

const std::wstring invalidSymbols = L"!@./[](){}$%^&*:;|'`<>,-+№?#";
const int MIN_INDEX = 0;

Game::Game() {}

std::wstring Game::getInvalidSymbols() { return invalidSymbols; }

bool Game::ValidateNickname(const std::wstring& nickname)
{
    for (wchar_t symbol : invalidSymbols)
        if (nickname.find(symbol) != std::wstring::npos)
            return false;

    if (nickname.size() < NICKNAME_MIN_LENGTH || nickname.size() > NICKNAME_MAX_LENGTH) return false;
    if (nickname.find(' ') != std::wstring::npos) return false;

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

        if (words.empty()) {
            std::wcout << RED << L"ERROR: Помилка зчитування файлу. Перевірте стан бази зі словами та повторіть спробу.\n" << WHT;
        } else {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            int randomIndex = std::rand() % words.size();
            return words[randomIndex];
        }
    } else {
        std::wcout << RED << L"ERROR: Помилка відкриття файлу. Перевірте стан бази зі словами та повторіть спробу.\n" << WHT;
    }

    return L"";
}

std::wstring Game::GetPartOfWord(const std::wstring& word, int position, int lettersCount)
{
    if (position < MIN_INDEX || position >= static_cast<int>(word.length())) {
        std::wcout << L"ERROR: Позиція не має бути за межами заданого слова.\n";
    } else if (lettersCount < MIN_INDEX || lettersCount > static_cast<int>(word.length()) - position) {
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

    if (guessedWord.find(letter) != std::wstring::npos) {
        letter = ' ';
        do {
            system("cls");
            std::wcout
                << WHT
                << L"╭───────────────────────────────────────────────────────────────────────────────╮\n"
                << L"│" << RED << L" ERROR: Введена літера вже була вгадана раніше. Повторіть спробу, будь-ласка.\t" << WHT << L"│\n"
                << L"╰───────────────────────────────────────────────────────────────────────────────╯\n";
            std::wcout << L" Введіть нову літеру: " << CYN;
            std::wcin >> letter;
        } while (guessedWord.find(letter) != std::wstring::npos);
    }

    if (word.find(letter) != std::wstring::npos) {
        std::wcout << YEL <<L" Вітаємо! Ви вгадали літеру!\n" << WHT;

        for (size_t i = MIN_INDEX; i < word.length(); i++) {
            if (word[i] == letter) {
                guessedWord[i] = letter;
            }
        }
    } else {
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
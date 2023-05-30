#include "Game.h"

// ����� �������, �� ������ �����������
const std::array<char, 25> invalidSymbols = { '!','@','.','/','[',']','(',')','$','%','^','&','*',':',';','"','`','<','>',',','-','+','�','?' };

Game::Game() {}

//bool Game::ValidateNickname(const std::wstring& nickName)
//{
//    if (nickName.find(' ') != std::string::npos) {
//        std::wcout << L"ERROR: ��'� ������ ������ ��������� �������. �������� �������� �������.\n"; 
//        return false;
//    } else if (nickName.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
//        std::wcout << L"ERROR: ��'� ������ ������ ��������� �������. �������� �������� �������.\n";
//        return false;
//    } else if (nickName.size() < this->NICKNAME_MIN_LENGTH || nickName.size() > this->NICKNAME_MAX_LENGTH) {
//        std::wcout << L"ERROR: ̳������� ������� ������� - " << this->NICKNAME_MIN_LENGTH << L", ����������� ������� ������� - " << NICKNAME_MAX_LENGTH << L". �������� �������� �������.\n";
//        return false;
//    } else return true;
//}

std::string Game::GenerateWord(const std::string& filePath)
{
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::wcout << L"ERROR: ������� �������� ����� � �������. �������� ���� �� ���� �� �������� ������.\n";
        return "";
    } else if (file.peek() == std::ifstream::traits_type::eof()) {
        std::wcout << L"ERROR: ����� ���� � ������� ������. ��������� ���� ������� �� �������� ������.\n";
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
        std::wcout << L"ERROR: ����� ������ ��������� �������. �������� ����������� ��������� ����� �� �������� ������.\n";
        return "";
    } else if (std::any_of(line.begin(), line.end(), ::isdigit)) {
        std::wcout << L"ERROR: ����� ������ ��������� �������. �������� ����������� ��������� ����� �� �������� ������.\n";
        return "";
    } else if (line.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
        std::wcout << L"ERROR: ����� ������ ��������� �������. �������� ����������� ��������� ����� �� �������� ������.\n";
        return "";
    }

    return line;
}

std::wstring Game::GetPartOfWord(const std::wstring& word, int position, int lettersCount)
{
    if (position < 0 || position >= static_cast<int>(word.length())) {
        throw std::out_of_range("ERROR: ������� �� �� ���� �� ������ �������� �����.\n");
    } else if (lettersCount < 0 || lettersCount > static_cast<int>(word.length()) - position) {
        throw std::out_of_range("ERROR: ʳ������ ���������� ���� �� �� ���� �� ������ �������� �����.\n");
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
            std::wcout << L"�� ������� �����.\n";
            std::cout << result << std::endl;
        } else {
            ++attempts;
            std::wcout << L"�� �� ������� �����. � ��� ���������� " << 8 - attempts << L" �����.\n";
            std::wcout << L"�������� �� �������� ����:\n";

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
            std::wcout << L"³����, �� ������� ��� �����!";
            found = true;
        }
    }
    return found;
}

int Game::GetNumOfLettersInWord(const std::string& word)
{
	return (int)word.length();
}

void Game::GameOver(const std::wstring& word)
{
    DesignHangman dh;
    std::wcout << L"��� ��������. �������� �����: " << word << std::endl;
    dh.HangmanStageEight();
}

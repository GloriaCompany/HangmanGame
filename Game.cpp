#include "Game.h"

// ����� �������, �� ������ �����������
const std::array<char, 25> invalidSymbols = { '!','@','.','/','[',']','(',')','$','%','^','&','*',':',';','"','`','<','>',',','-','+','�','?' };

void Game::ValidateNickname(std::string& nickName)
{
    if (nickName.find(' ') != std::string::npos)
        std::cout << "ERROR: ��'� ������ ������ ��������� �������. �������� �������� �������.\n";
    else if (nickName.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos)
        std::cout << "ERROR: ��'� ������ ������ ��������� �������. �������� �������� �������.\n";
    else if (nickName.size() < this->NICKNAME_MIN_LENGTH || nickName.size() > this->NICKNAME_MAX_LENGTH)
        std::cout << "ERROR: ̳������� ������� ������� - " << this->NICKNAME_MIN_LENGTH << ", ����������� ������� ������� - " << NICKNAME_MAX_LENGTH << ". �������� �������� �������.\n";
}

std::string Game::GenerateWord(std::string& filePath)
{
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cout << "ERROR: ������� �������� ����� � �������. �������� ���� �� ���� �� �������� ������.\n";
        return "";
    } else if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "ERROR: ����� ���� � ������� ������. ��������� ���� ������� �� �������� ������.\n";
        return "";
    }

    int lineCount = 0;
    std::string line;
    while (std::getline(file, line))
        ++lineCount;

    std::srand(std::time(nullptr));
    int lineNumber = std::rand() % lineCount + 1;

    file.clear();
    file.seekg(0, std::ios::beg);
    for (int i = 1; i <= lineNumber; ++i)
        std::getline(file, line);

    if (line.find(' ') != std::string::npos) {
        std::cout << "ERROR: ����� ������ ��������� �������. �������� ����������� ��������� ����� �� �������� ������.\n";
        return "";
    } else if (std::any_of(line.begin(), line.end(), ::isdigit)) {
        std::cout << "ERROR: ����� ������ ��������� �������. �������� ����������� ��������� ����� �� �������� ������.\n";
        return "";
    } else if (line.find_first_of(invalidSymbols.data(), 0, invalidSymbols.size()) != std::string::npos) {
        std::cout << "ERROR: ����� ������ ��������� �������. �������� ����������� ��������� ����� �� �������� ������.\n";
        return "";
    }

    return line;
}

std::string Game::GetPartOfWord(std::string& word, int position, int lettersCount)
{
    if (position < 0 || position >= static_cast<int>(word.length())) {
        throw std::out_of_range("ERROR: ������� �� �� ���� �� ������ �������� �����.\n");
    } else if (lettersCount < 0 || lettersCount > static_cast<int>(word.length()) - position) {
        throw std::out_of_range("ERROR: ʳ������ ���������� ���� �� �� ���� �� ������ �������� �����.\n");
    }

    return word.substr(position, lettersCount);
}

bool Game::CheckLetterInWord(std::string& word, char letter)
{
    bool found = false;
    int attempts = 0;
    std::string result(word.length(), '_');

    while (!found && attempts < 8) {
        bool letterFound = false;

        for (int i = 0; i < word.length(); ++i) {
            if (word[i] == letter) {
                result[i] = letter;
                letterFound = true;
            }
        }

        if (letterFound) {
            std::cout << "�� ������� �����.\n";
            std::cout << result << std::endl;
        } else {
            ++attempts;
            std::cout << "�� �� ������� �����. � ��� ���������� " << 8 - attempts << " �����.\n";
            std::cout << "�������� �� �������� ����:\n";
            if (attempts == 1) {
                // 1 ���� ��������
            } else if (attempts == 2) {
                // 2 ���� ��������
            } else if (attempts == 3) {
                // 3 ���� ��������
            } else if (attempts == 4) {
                // 4 ���� ��������
            } else if (attempts == 5) {
                // 5 ���� ��������
            } else if (attempts == 6) {
                // 6 ���� ��������
            } else if (attempts == 7) {
                // 7 ���� ��������
            } else if (attempts == 8) {
                GameOver(word);
            } else {
                std::cout << result << std::endl;
            }
        }

        if (result == word) {
            std::cout << "³����, �� ������� ��� �����!";
            found = true;
        }
    }
}

int Game::GetNumOfLettersInWord(std::string& word)
{
	return word.length();
}

void Game::GameOver(std::string& word)
{
    std::cout << "��� ��������. �������� �����: " << word << std::endl;
    // ����� ��������
}

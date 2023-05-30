#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <array>

#include "DesignHangman.h"

class Game
{
private:
	const int NICKNAME_MIN_LENGTH = 5, NICKNAME_MAX_LENGTH = 15;
public:
	Game();

	bool ValidateNickname(const std::string& nickName);
	std::string GenerateWord(const std::string& filePath);
	std::wstring GetPartOfWord(const std::wstring& word, int position, int lettersCount);
	bool CheckLetterInWord(const std::string& word, char letter);
	int GetNumOfLettersInWord(const std::string& word);
	void GameOver(const std::wstring& word);
};


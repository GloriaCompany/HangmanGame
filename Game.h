#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <array>

#include "DesignHangman.h"
#include "Player.h"

class Game
{
private:
	const int NICKNAME_MIN_LENGTH = 5, NICKNAME_MAX_LENGTH = 15;
	Player player1, player2;
public:
	Game();

	std::string getInvalidSymbols();
	bool ValidateNickname(const std::string& nickName);
	std::string GenerateWord(const std::string filePath);
	std::string GetPartOfWord(const std::string& word, int position, int lettersCount);
	void CheckLetterInWord(const std::string& word, char letter);
	int GetNumOfLettersInWord(const std::string& word);
	void GameOver(const std::string& word);
};


#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <array>

class Game
{
private:
	const int NICKNAME_MIN_LENGTH = 5, NICKNAME_MAX_LENGTH = 15;
public:
	void ValidateNickname(std::string& nickName);
	std::string GenerateWord(std::string& filePath);
	std::string GetPartOfWord(std::string& word, int position, int lettersCount);
	bool CheckLetterInWord(std::string& word, char letter);
	int GetNumOfLettersInWord(std::string& word);
	void GameOver(std::string& word);
};


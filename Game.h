#include <string>

class Game
{
public:
	bool ValidateNickname(std::string nickname);
	std::string GenerateWord();
	std::string GetPartOfWord(std::string word);
	int CheckLetterInWord(std::string word);
	int GetNumOfLettersInWord(std::string word);
	void GameOver();
};


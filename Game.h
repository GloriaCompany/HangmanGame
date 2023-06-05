﻿#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <array>
#include <codecvt>

#include "DesignHangman.h"
#include "Player.h"

class Game
{
private:
	const int NICKNAME_MIN_LENGTH = 5, NICKNAME_MAX_LENGTH = 15;
public:
	Game();

	std::wstring getInvalidSymbols();
	bool ValidateNickname(const std::wstring& nickName);
	std::wstring GenerateWord(const std::wstring filePath);
	std::wstring GetPartOfWord(const std::wstring& word, int position, int lettersCount);
	bool IsAllLettersGuessed(const std::wstring& word, const std::wstring& guessedWord);
	void CheckLetterInWord(Player& player, const std::wstring& word, std::wstring& guessedWord, wchar_t letter);
};


#pragma once
#include <string>

class Player
{
private:
	std::wstring name;
	int score;
public:
	std::wstring getName();
	int getScore();

	void setName(std::wstring _name);
	void setScore(int _score);

	void Auth(std::wstring _name);
};


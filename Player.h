#pragma once
#include <string>

class Player
{
private:
	std::string name;
	int score;
public:
	std::string getName();
	int getScore();

	void setName(std::string& _name);
	void setScore(int _score);
};


#pragma once
#include <string>

class Player
{
private:
	std::string name;
	int attempts = 8;
public:
	std::string getName();
	int getAttempts() const;
	
	void setName(std::string& _name);

	void decrementAttempts();
};


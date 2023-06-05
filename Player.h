#pragma once
#include <string>

class Player
{
private:
	std::wstring name;
	int attempts = 8;
public:
	std::wstring getName();
	int getAttempts() const;
	
	void setName(std::wstring& _name);
	void setAttempts(int attempts);

	void decrementAttempts();
};


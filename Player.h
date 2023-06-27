#pragma once
#include <string>

class Player
{
private:
	std::wstring name;
	int attempts = 8;
public:
	std::wstring getName() const;
	int getAttempts() const;
	
	void setName(std::wstring& _name);
	void setAttempts(int _attempts);

	void decrementAttempts();
};


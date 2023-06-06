#include "Player.h"

std::wstring Player::getName() const { return this->name; }
int Player::getAttempts() const { return this->attempts; }

void Player::setName(std::wstring& _name) { this->name = _name; }
void Player::setAttempts(int _attempts) { this->attempts = _attempts; }

void Player::decrementAttempts() { this->attempts--; }

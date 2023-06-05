#include "Player.h"

std::wstring Player::getName() { return this->name; }
int Player::getAttempts() const { return attempts; }

void Player::setName(std::wstring& _name) { this->name = _name; }

void Player::decrementAttempts() { this->attempts--; }

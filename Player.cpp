#include "Player.h"

std::string Player::getName() { return this->name; }
int Player::getAttempts() const { return attempts; }

void Player::setName(std::string& _name) { this->name = _name; }

void Player::decrementAttempts() { this->attempts--; }

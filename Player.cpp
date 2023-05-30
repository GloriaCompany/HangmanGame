	#include "Player.h"

std::wstring Player::getName() { return this->name; }
int Player::getScore() { return this->score; }

void Player::setName(std::wstring _name) { this->name = _name; }
void Player::setScore(int _score) { this->score = _score; }

void Player::Auth(std::wstring _name)
{

}
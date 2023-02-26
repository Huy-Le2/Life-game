#include "Player.hpp"


Player::Player(string name, int money){
	this->name = name;
	this->money = money;
}

string Player::getName()
{
	return name;
}

void Player::addMoney(int amount)
{
	this->money += amount;
}

void Player::modifyPersonality(int modifier[3])
{
	int i = 0;
	for (i; i < 3; i++) {
		this->personality[i] += modifier[i];
	}
}
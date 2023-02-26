#ifndef _PLAYER_HPP
#define _PLAYER_HPP
#include <iostream>

using namespace std;

struct Player {
	Player(string name, int money);
	string getName();
	void addMoney(int amount);
	void modifyPersonality(int modifiers[3]);

	string name;
	int money;
	int personality[3] = {0,0,0};

};

#endif

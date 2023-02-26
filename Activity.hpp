#include <iostream>

using namespace std;
#include "Player.hpp"

class Activity
{
private:
	string id;
	string name;
	string description;
	string attribute[2];
	int cost;

public:
	Activity(string name, string description, int cost, string attribute[2]);
	void takeFee(Player* character);
	void affectPlayer(Player* character);
	string getName();
	string getDescription();


};
#include "Activity.hpp"

Activity::Activity(string name, string description, int cost, string attribute[2])
{
	this->name = name;
	this->cost = cost;
	this->description = description;

	for (int i = 0; i < 2; i++) {
		this->attribute[i] = attribute[i];
	}

}

void Activity::takeFee(Player* character)
{
	character->addMoney(-cost);

}

void Activity::affectPlayer(Player* character)
{
	int personality_set[3] = { 0,0,0 };
	if (attribute[0] == "Outdoor")
		personality_set[0] += 1;
	else if (attribute[0] == "Very Outdoor")
	{
		personality_set[0] += 1;
		personality_set[1] -= 1;
	}
	if (attribute[0] == "Indoor")
		personality_set[1] += 1;
	else if (attribute[0] == "Very Indoor")
	{
		personality_set[1] += 1;
		personality_set[0] -= 1;
	}
	if (attribute[1] == "Luxury")
		personality_set[2] += 1;
	character->modifyPersonality(personality_set);
}

string Activity::getName()
{
	return name;
}

string Activity::getDescription()
{
	return description;
}

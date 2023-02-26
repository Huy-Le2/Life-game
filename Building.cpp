#include "Building.hpp"

using namespace std;

Building::Building()
{
	Setup({});
}

Building::Building(string name, string description, string attribute[2], string activities[5])
{
	Setup(activities,  name,  description,  attribute[2]);
}

void Building::Setup(string activities[5], string name, string description,
	string attribute)
{
	int i = 0;
	this->name = name;
	this->description = description;
	this->attribute = attribute;

	for (i; i < 5; i++)
		this->activities[i] = activities[i];

}

void Building::affectPlayer(Player* character)
{
	int personality_set[3] = { 0,0,0 };
	if (this->attribute == "Outdoor")
		personality_set[0] += 1;
	else if (this->attribute == "Very Outdoor")
	{
		personality_set[0] += 1;
		personality_set[1] -= 1;
	}
	if (this->attribute == "Indoor")
		personality_set[1] += 1;
	else if (attribute == "Very Indoor")
	{
		personality_set[1] += 1;
		personality_set[0] -= 1;
	}
	if (attribute == "Luxury")
		personality_set[2] += 1;
	character->modifyPersonality(personality_set);
}

void Building::OutputBuildingInfo()
{
	cout << "\t" << description << "\n";
}

bool Building::setupActivities(string activities[5])
{
	string filename = "activities_list.txt";
	ifstream input(filename);
	if (!input.good())
	{
		return false;
	}	
	string buffer;
	string tempt;
	string id;
	string act_name, act_attribute[2];
	int act_cost;
	
	
	while (input >> buffer)
	{
		if (buffer == "ACT_BEGIN")
		{
			input >> id;
			input.ignore();
			getline(input, act_name);
			getline(input, tempt);
			stringstream true_cost(tempt);
			true_cost >> act_cost;
			getline(input, act_attribute[0]);
			getline(input, act_attribute[1]);


		}
	}

}

void Building::OutputActivityInfo()
{


}
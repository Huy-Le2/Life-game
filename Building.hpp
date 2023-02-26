#include <iostream>
#include <vector>
#include "Activity.hpp"
#include "Player.hpp"
#include "enums.hpp"
#include "Utilities.hpp"
#include <fstream>
#include <istream>

using namespace std;

class Building {
private:
	string name;
	string description;
	string attribute;
	string activities[5];
	vector<Activity*> v_Activities;
public:
	Building();
	Building(string name, string description, string attribte[2], string activities[5]);
	void affectPlayer(Player* character);
	void Setup(string activities[5], string name = " ", string description = " ",
			   string attribute = {" "," "});

	void OutputActivityInfo();
	void OutputBuildingInfo();
	bool setupActivities(string activities[5]);

};
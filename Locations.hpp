#include <iostream>
#include "enums.hpp"
#include "Utilities.hpp"
#include <string>
using namespace std;

struct Location
{
	Location();
	Location(string id, string name, string description);
	void SetupNeighbors(string north, string south, string west, string east);
	void Setup(string id = " ", string name = " ", string description = " ");

	void OutputLocationInfo();
	void Outputneighbor();
	bool canGo(Direction direction);
	string getNeighborID(Direction direction);
	string getID();

	string id;
	string name;
	string description;
	string neighborsID[4];

};
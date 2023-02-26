#include "Locations.hpp"

Location::Location()
{
	Setup();
}

Location::Location(string id, string name, string description)
{
	Setup(id, name, description);

}

void Location::Setup(string id, string name, string description)
{
	this->id = id;
	this->name = name;
	this->description = description;

	for (int i = 0; i < 4; i++)
	{
		neighborsID[i] = "\0";
	}
}

void Location::SetupNeighbors(string north, string south, string east, string west)
{
	neighborsID[NORTH] = north;
	neighborsID[SOUTH] = south;
	neighborsID[EAST] = east;
	neighborsID[WEST] = west;
}

void Location::OutputLocationInfo() 
{
	Menu::ClearScreen();
	Menu::Header(name);
	cout << "\t" << description << endl;
}


void Location::Outputneighbor()
{

}

bool Location::canGo(Direction direction)
{
	for (int i = 0; i < 4; i++)
	{
		if (direction == Direction(i) && neighborsID[i] != "NULL")
		{
			return true;
		}
	}

	return false;
}

string Location::getNeighborID(Direction direction)
{
	return neighborsID[direction];
}

string Location::getID()
{

	return id;
}
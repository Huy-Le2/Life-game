#include <iostream>
#include <string>
#include <map>

#include "Locations.hpp"

using namespace std;


class Game {
public:
    Game();
    ~Game();

    void Run();

private:

    bool SetupRooms();
    void CreateLocation(string id, string name, string description, string north, string south, string east, string west);
    string HandleUserInput();
    Location* m_ptrCurrentLocation;
    map<string, Location*> m_Location;
    bool m_done;
    string m_endRoomId;



};
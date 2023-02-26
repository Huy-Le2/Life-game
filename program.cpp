#include <iostream>

using namespace std;
#include "program.hpp"
#include "Logger.hpp"
#include "Utilities.hpp"

Game::Game()
{
    Logger::Out("Function start", "Program::Program");
    m_ptrCurrentLocation = nullptr;
    m_done = false;

    bool success = SetupRooms();
    if (!success)
    {
        m_done = true;
    }

}

void Game::Run()
{
    Logger::Out("Function start", "Program::Run");
    string status = "";

    if (m_done) { Logger::Out("Program is exited unexpectedly", "Program::Run"); }

    while (!m_done)
    {
        m_ptrCurrentLocation->OutputLocationInfo();

        if (m_ptrCurrentLocation->getID() == m_endRoomId)
        {
            m_done = true;
            continue;
        }

        m_ptrCurrentLocation->Outputneighbor();

        cout << endl << endl;

        status = HandleUserInput();

        cout << "\t" << status << endl;
        Menu::Pause();
    }

    cout << endl << "           The end." << endl;
    Menu::Pause();

}

bool Game::SetupRooms()
{
    string filename = "maps.txt";
    Logger::Out("Function start", "Program::SetupRooms");
    ifstream input(filename);

    if (!input.good())
    {
        Logger::Out("Error opening file", "Program::SetupRooms");
        return false;
    }
    string buffer;

    string id, name, description, northId, southId, eastId, westId;

    while (input >> buffer)
    {
        if (buffer == "ROOM_BEGIN")
        {
            input >> id;
            input.ignore();
            getline(input, name);
            getline(input, description);

            input >> buffer; // NORTH
            input >> northId;

            input >> buffer; // SOUTH
            input >> southId;

            input >> buffer; // EAST
            input >> eastId;

            input >> buffer; // WEST
            input >> westId;

            CreateLocation(id, name, description, northId, southId, eastId, westId);
        }
        else if (buffer == "STARTING_ROOM")
        {
            input >> buffer;
            m_ptrCurrentLocation = m_Location[buffer];

            Logger::Out("Set STARTING ROOM to " + buffer, "Program::SetupRooms");
        }
        else if (buffer == "ENDING_ROOM")
        {
            input >> m_endRoomId;

            Logger::Out("Set ENDING ROOM to " + m_endRoomId, "Program::SetupRooms");
        }
    }

    return true;
}

void Game::CreateLocation(string id, string name, string description, string north, string south, string east, string west)
{
    Logger::Out("Function start", "Program::CreateRoom");
    m_Location[id] = new Location(id, name, description);
    m_Location[id]->SetupNeighbors(north, south, east, west);
}

Game::~Game()
{
    Logger::Out("Function start", "Program::~Program");
    for (auto& ptrLocation : m_Location)
    {
        if (ptrLocation.second != nullptr)
        {
            delete ptrLocation.second;
        }
    }
}

string Game::HandleUserInput()
{
    Logger::Out("Function start", "Program::HandleUserInput");
    string status = "";

    string userInput = Menu::GetStringLine("Now what?");

    Logger::Out("User entered \"" + userInput + "\"", "Program::HandleUserInput");

    bool userInputMovement = false;
    for (int i = 0; i < 4; i++)
    {
        Direction direction = Direction(i);

        string command1 = StringUtil::ToLower(GetDirectionString(direction));
        string command2 = command1.substr(0, 1);

        if (userInput == command1 || userInput == command2)
        {
            userInputMovement = true;
            Logger::Out("Try to move " + command1, "Program::HandleUserInput");
            if (m_ptrCurrentLocation->canGo(direction))
            {
                status = "You went " + GetDirectionString(direction);
                string key = m_ptrCurrentLocation->getNeighborID(direction);
                Logger::Out("Neighbor ID for the " + command1 + ": " + key, "Program::HandleUserInput");
                m_ptrCurrentLocation = m_Location[key];
            }
            else
            {
                status = "You cannot go " + GetDirectionString(direction) + " here!";
                break;
            }
        }
    }

    if (!userInputMovement)
    {
        status = "Unknown command";
    }

    Logger::Out("Resulting status: \"" + status + "\"", "Program::HandleUserInput");
    return status;
}
#include <iostream>

using namespace std;
#include "program.hpp"
#include "Logger.hpp"
int main()
{

	Logger::Setup(false);
	Game Game;
	Game.Run();
	Logger::Cleanup();

	return 0;
}
#ifndef _enums_hpp
#define _enums_hpp

#include <string>
using namespace std;

enum Direction { NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3 };

string GetDirectionString(Direction direction);

#endif

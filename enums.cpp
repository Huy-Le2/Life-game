#include "enums.hpp"

string GetDirectionString(Direction direction)
{
    if (direction == NORTH) { return "NORTH"; }
    else if (direction == SOUTH) { return "SOUTH"; }
    else if (direction == EAST) { return "EAST"; }
    else if (direction == WEST) { return "WEST"; }
    else { return "UNKNOWN"; }
}

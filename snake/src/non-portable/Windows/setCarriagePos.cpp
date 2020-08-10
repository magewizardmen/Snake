
#include "../../../headers/non-portable.h"


void 
setCarriagePos(const Position& position) {
	COORD coord;
	coord.X = position.first;
	coord.Y = position.second;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#include "../headers/snake.h"

void change_direction(Snake& snake) {
	enum {
		Left = 75,
		Up = 72,
		Right = 77,
		Down = 80
	} Directions;


	if (_kbhit()) {
	int c;	
		if (_getch() == 224)
			c = _getch();

		switch (c) {
		case Left: snake.direction = std::pair<int, int>(0, -1); break;
		case Up: snake.direction = std::pair<int, int>(-1, 0); break;
		case Right: snake.direction = std::pair<int, int>(0, 1); break;
		case Down: snake.direction = std::pair<int, int>(1, 0); break;
		}
	}
}
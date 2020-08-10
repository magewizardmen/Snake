#include "../headers/snake.h"
#include "../const.h"

namespace {
	std::pair<int, int> 
	operator+(std::pair<int, int> a, std::pair<int, int> b) { return std::pair<int, int>(a.first + b.first, a.second + b.second); }
};



Snake::
Snake(const Position& pos, Direction direction) : body{ pos }, direction(direction) {}



const SnakeBody Snake::
move(int resultOfCheking) {

	auto it = body.begin();
	auto end = --body.end();

	while (end != body.begin()) {
		auto current = end--;
		*current = *end;
	}
	
	if (resultOfCheking == 2) {
		body.push_back(*it);
		*it = *it + direction;
	}
	else
	*it = *it + direction;


	return body;
}

const int Snake::
checkCollisions(const Field& field) const  {
	return field.at(*body.begin() + direction) == FREE_SPACE_CHAR ? 1 : field.at(*body.begin() + direction) == EAT_CHAR ? 2 : 0;
}

void Snake::
changeDirection() {
	enum {
		Left = non_portable::LEFT,
		Up = non_portable::UP,
		Right = non_portable::RIGHT,
		Down = non_portable::DOWN
	} Directions;
	
	switch (getChar()) {
	case Left: if (direction.second - 1 != 0) direction = Direction(0, -1); break;
	case Up: if (direction.first - 1 != 0)direction = Direction(-1, 0); break;
	case Right: if (direction.second + 1 != 0)direction = Direction(0, 1); break;
	case Down: if (direction.first + 1 != 0)direction = Direction(1, 0); break;
	}
}

const SnakeBody Snake::
getBody() const { return body; }



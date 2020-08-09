#include "../headers/snake.h"
#include "../Const.h"

namespace {
	std::pair<int, int> operator+(std::pair<int, int> a, std::pair<int, int> b) { return std::pair<int, int>(a.first + b.first, a.second + b.second); }
};



Snake::Snake(int x, int y, std::pair<int, int> direction) : body{ std::pair<int, int>(x, y) }, direction(direction) {}

const std::list<std::pair<int, int>> Snake::move(int check) {

	auto it = body.begin();
	auto end = --body.end();

	while (end != body.begin()) {
		auto current = end--;
		*current = *end;
	}
	
	if (check == 2) {
		body.push_back(*it);
		*it = *it + direction;
	}
	else
	*it = *it + direction;


	return body;
}

const int Snake::check(const std::map<std::pair<int, int>, char>& field) const  {
	return field.at(*body.begin() + direction) == free_space_char ? 1 : field.at(*body.begin() + direction) == eat_char ? 2 : 0;
}

void Snake::change_direction() {
	enum {
		Left = non_portable::Left,
		Up = non_portable::Up,
		Right = non_portable::Right,
		Down = non_portable::Down
	} Directions;

	int c = getChar();


	switch (c) {
	case Left: if (direction.second - 1 != 0) direction = std::pair<int, int>(0, -1); break;
	case Up: if (direction.first - 1 != 0)direction = std::pair<int, int>(-1, 0); break;
	case Right: if (direction.second + 1 != 0)direction = std::pair<int, int>(0, 1); break;
	case Down: if (direction.first + 1 != 0)direction = std::pair<int, int>(1, 0); break;
	}
}

const std::list<std::pair<int, int>> Snake::getBody() const { return body; }



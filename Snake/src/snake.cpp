#include "../headers/snake.h"

namespace {
	std::pair<int, int> operator+(std::pair<int, int> a, std::pair<int, int> b) { return std::pair<int, int>(a.first + b.first, a.second + b.second); }
};



Snake::Snake(int x, int y, std::pair<int, int> direction) : body{ std::pair<int, int>(x, y) }, direction(direction) {}

std::list<std::pair<int, int>> Snake::move() {


	auto it = body.begin();
	auto end = --body.end();
	while (it != end) {
		auto current = it--;
		*current = *it;
	}
	*it = *it + direction;

	return body;
}

int Snake::check(const std::map<std::pair<int, int>, char>& field) {
	return field.at(*body.begin() + direction) == 'B' ? 0 : field.at(*body.begin() + direction) == ' ' ? 1 : 2;
}


#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <algorithm>
#include <map>

#include "functions.h"

class Snake {
	std::list<std::pair<int, int>> body;
	std::pair<int, int> direction;


public:
	explicit Snake(int x = 1, int y = 1, std::pair<int, int> direction = std::pair<int, int>(1, 0));


	const std::list<std::pair<int, int>> move();

	const int check(const std::map<std::pair<int, int>, char>&) const;

	const std::list<std::pair<int, int>> getBody() const;

	void change_direction();

};

#endif 


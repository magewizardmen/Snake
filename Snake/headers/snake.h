#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <algorithm>
#include <map>

class Snake {
	std::list<std::pair<int, int>> body;
	std::pair<int, int> direction;

public:
	explicit Snake(int x = 1, int y = 1, std::pair<int, int> direction = std::pair<int, int>(0, 1));


	std::list<std::pair<int, int>> move();

	int check(const std::map<std::pair<int, int>, char>& field);

};

#endif 

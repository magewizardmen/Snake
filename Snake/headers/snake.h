#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <algorithm>
#include <map>

class Snake {
	std::list<std::pair<int, int>> body;
	std::pair<int, int> direction;

public:
	explicit Snake(int x, int y, std::pair<int, int> direction);


	std::list<std::pair<int, int>> move();

	int check(const std::map<std::pair<int, int>, char>& field);

};

#endif 

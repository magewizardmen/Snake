#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <algorithm>
#include <map>



#include <conio.h>
#include <thread>

class Snake {
	std::list<std::pair<int, int>> body;
	std::pair<int, int> direction;

	void grow() {

	}

public:
	explicit Snake(int x = 1, int y = 1, std::pair<int, int> direction = std::pair<int, int>(1, 0));


	std::list<std::pair<int, int>> move();

	int check(const std::map<std::pair<int, int>, char>& field);

	friend void change_direction(Snake&);
};

#endif 

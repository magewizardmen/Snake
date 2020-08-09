#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <algorithm>
#include <map>

#include "functions.h"




typedef std::map<std::pair<int, int>, char> Field;
typedef std::pair<int, int> FieldSize;
typedef std::pair<int, int> Position;
typedef std::list<std::pair<int, int>> SnakeBody;
typedef std::pair<int, int> Direction;



class Snake {
public:

	explicit Snake(const Position& = Position(1, 1), Direction direction = Direction(1, 0));



	const SnakeBody 
		move(int);

	const int 
		checkCollisions(const Field&) const;

	const SnakeBody 
		getBody() const;

	void 
		changeDirection();

private:

	SnakeBody body;
	Direction direction;


};

#endif 


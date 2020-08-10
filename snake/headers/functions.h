#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <list>
#include <vector>

#include"non-portable.h"


typedef std::map<Position, char> Field;
typedef std::pair<std::pair<int, int>, char> FieldCell;
typedef std::pair<int, int> Position;
typedef std::pair<int, int> FieldSize;
typedef std::list<std::pair<int, int>> SnakeBody;



std::unique_ptr<Field> 
createField(const FieldSize&);

void 
writeField(const Field&, const FieldSize&);

void 
drawSnake(const SnakeBody&, Field&);

void 
redrawScreen(Field&, const Field&);

const Position
spawnEat(const Field&, Field&, const FieldSize&, bool&);



//NON-PORTABLES

void 
setCarriagePos(const Position&);

void 
mySleep(int);

int 
getChar();

#endif

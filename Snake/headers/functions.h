#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <list>
#include <vector>

#include"non-portable.h"

std::unique_ptr<std::map<std::pair<int, int>, char>> createField(const std::pair<int, int>&);

void writeField(const std::map<std::pair<int, int>, char>&, const std::pair<int, int>&);

void drawSnake(const std::list<std::pair<int, int>>&, std::map<std::pair<int, int>, char>&);

void redrawScreen(std::map<std::pair<int, int>, char>&, const std::map<std::pair<int, int>, char>&);

const std::pair<int,int> spawnEat(const std::map<std::pair<int, int>, char>&, std::map<std::pair<int, int>, char>&, const std::pair<int, int>&, bool&);



//NON-PORTABLES

void setCarriagePos(int, int);

void mySleep(int);

int getChar();

#endif

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <list>
#include <vector>

#include"non-portable.h"

std::shared_ptr<std::map<std::pair<int, int>, char>> create_field(const std::pair<int, int>&);

void write_field(const std::map<std::pair<int, int>, char>&, const std::pair<int, int>&);

void draw_snake(const std::list<std::pair<int, int>>&, std::map<std::pair<int, int>, char>&);

void redraw_scr(std::map<std::pair<int, int>, char>&, const std::map<std::pair<int, int>, char>&);

const std::pair<int,int> spawn_eat(std::map<std::pair<int, int>, char>&, const std::pair<int, int>&, bool&);



//NON-PORTABLES

void setCarriagePos(int, int);

void mySleep(int);

int getChar();

#endif

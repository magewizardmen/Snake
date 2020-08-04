#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <list>

std::unique_ptr<std::map<std::pair<int, int>, char>> create_field(int, int);

void write_field(const std::map<std::pair<int, int>, char>&, int, int);

void draw_snake(std::list<std::pair<int, int>>&, std::map<std::pair<int, int>, char>&);


#endif

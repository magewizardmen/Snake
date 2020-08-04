#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <list>

#include <vector>

std::unique_ptr<std::map<std::pair<int, int>, char>> create_field(const std::pair<int, int>&);

void write_field(const std::map<std::pair<int, int>, char>&, const std::pair<int, int>&);

void draw_snake(const std::list<std::pair<int, int>>&, std::map<std::pair<int, int>, char>&);

void clear_scr(std::map<std::pair<int, int>, char>&, const std::map<std::pair<int, int>, char>&);

int spawn_eat(std::map<std::pair<int, int>, char>&, const std::pair<int, int>&);

#endif

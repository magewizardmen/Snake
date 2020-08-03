#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>

std::unique_ptr<std::map<std::pair<int, int>, char>> create_field(int height, int width);

void write_field(const std::map<std::pair<int, int>, char>& field, int height, int width);




#endif

#include "../headers/functions.h"
#include "../Const.h"


std::unique_ptr<std::map<std::pair<int, int>, char>> create_field(const std::pair<int, int>& field_size) {

	std::unique_ptr<std::map<std::pair<int, int>, char>> field = std::make_unique<std::map<std::pair<int, int>, char>>();

	for (int i = 0; i < field_size.first; i++) 
		for (int j = 0; j < field_size.second; j++)
			field->insert(std::pair<std::pair<int,int>, char>(std::pair<int, int>(i, j), i == 0 ? border_field_char : i == field_size.first - 1 ? border_field_char : j == 0 ? border_field_char : j == field_size.second - 1 ? border_field_char : free_space_char));
	return field;
}

void write_field(const std::map<std::pair<int, int>, char>& field, const std::pair<int, int>& field_size) {
	for (int i = 0; i < field_size.first;i++) {
		for (int j = 0; j < field_size.second;j++) {
			std::cout << field.at(std::pair<int, int>(i, j));
		}
		std::cout << std::endl;
	}
}

void draw_snake(const std::list<std::pair<int, int>>& body, std::map<std::pair<int, int>, char>& field) {
	std::for_each(body.begin(), body.end(), [&](const std::pair<int, int>& key) {field.at(key) = snake_body_char;});
	field.at(*body.begin()) = snake_head_char;
}

void redraw_scr(std::map<std::pair<int, int>, char>& field, const std::map<std::pair<int, int>, char>& copy_field) {
	field = copy_field;
	setCarriagePos(0, 0);
}

const std::pair<int, int> spawn_eat(const std::map<std::pair<int, int>, char>& field, std::map<std::pair<int, int>, char>& copy_field, const std::pair<int, int>& field_size, bool& is_exist) {
	static std::pair<int, int> pos;

	if (!is_exist) {
		std::vector<std::pair<int, int>> possible_positions;

		for (int i = 1; i < field_size.first - 1; i++)
			for (int j = 1; j < field_size.second - 1; j++)
				if ((copy_field.at(std::pair<int, int>(i, j)) == free_space_char)&&(field.at(std::pair<int, int>(i, j)) == free_space_char)) possible_positions.push_back(std::pair<int, int>(i, j));

		//if (possible_positions.size() == 0) return 1;

		pos = possible_positions[rand() % possible_positions.size()];

		
		copy_field.at(pos) = eat_char;
		is_exist = 1;
	}	
	return pos;
}
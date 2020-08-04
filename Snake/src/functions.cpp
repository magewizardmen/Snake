#include "../headers/functions.h"

const char snake_body = 'Z';

std::unique_ptr<std::map<std::pair<int, int>, char>> create_field(const std::pair<int, int>& field_size) {

	const char border = 'B';
	const char space = ' ';


	std::unique_ptr<std::map<std::pair<int, int>, char>> field = std::make_unique<std::map<std::pair<int, int>, char>>();

	for (int i = 0; i < field_size.first; i++) {
		for (int j = 0; j < field_size.second; j++)
			field->insert(std::pair<std::pair<int,int>, char>(std::pair<int, int>(i, j), i == 0 ? border : i == field_size.first - 1 ? border : j == 0 ? border : j == field_size.second - 1 ? border : space));
	}
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
	std::for_each(body.begin(), body.end(), [&](const std::pair<int, int>& key) {field.at(key) = 'Z';});
}

void clear_scr(std::map<std::pair<int, int>, char>& field, const std::map<std::pair<int, int>, char>& copy_field) {
	field = copy_field;
	system("cls");
}
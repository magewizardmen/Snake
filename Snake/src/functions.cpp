#include "../headers/functions.h"
#include "../const.h"


std::unique_ptr<std::map<std::pair<int, int>, char>> createField(const std::pair<int, int>& fieldSize) {

	std::unique_ptr<std::map<std::pair<int, int>, char>> field = std::make_unique<std::map<std::pair<int, int>, char>>();

	for (int i = 0; i < fieldSize.first; i++) 
		for (int j = 0; j < fieldSize.second; j++)
			field->insert(std::pair<std::pair<int,int>, char>(std::pair<int, int>(i, j), i == 0 ? BORDER_FIELD_CHAR : i == fieldSize.first - 1 ? BORDER_FIELD_CHAR : j == 0 ? BORDER_FIELD_CHAR : j == fieldSize.second - 1 ? BORDER_FIELD_CHAR : FREE_SPACE_CHAR));
	return field;
}

void writeField(const std::map<std::pair<int, int>, char>& field, const std::pair<int, int>& fieldSize) {
	for (int i = 0; i < fieldSize.first;i++) {
		for (int j = 0; j < fieldSize.second;j++) {
			std::cout << field.at(std::pair<int, int>(i, j));
		}
		std::cout << std::endl;
	}
}

void drawSnake(const std::list<std::pair<int, int>>& body, std::map<std::pair<int, int>, char>& field) {
	std::for_each(body.begin(), body.end(), [&](const std::pair<int, int>& key) {field.at(key) = SNAKE_BODY_CHAR;});
	field.at(*body.begin()) = SNAKE_HEAD_CHAR;
}

void redrawScreen(std::map<std::pair<int, int>, char>& field, const std::map<std::pair<int, int>, char>& copyField) {
	field = copyField;
	setCarriagePos(0, 0);
}

const std::pair<int, int> spawnEat(const std::map<std::pair<int, int>, char>& field, std::map<std::pair<int, int>, char>& copyField, const std::pair<int, int>& fieldSize, bool& isExist) {
	static std::pair<int, int> pos;

	if (!isExist) {
		std::vector<std::pair<int, int>> possible_positions;

		for (int i = 1; i < fieldSize.first - 1; i++)
			for (int j = 1; j < fieldSize.second - 1; j++)
				if ((copyField.at(std::pair<int, int>(i, j)) == FREE_SPACE_CHAR)&&(field.at(std::pair<int, int>(i, j)) == FREE_SPACE_CHAR)) possible_positions.push_back(std::pair<int, int>(i, j));

		//if (possible_positions.size() == 0) return 1;

		pos = possible_positions[rand() % possible_positions.size()];

		
		copyField.at(pos) = EAT_CHAR;
		isExist = 1;
	}	
	return pos;
}
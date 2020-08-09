#include "../const.h"
#include "../headers/functions.h"



std::unique_ptr<Field> 
createField(const FieldSize& fieldSize) {
	std::unique_ptr<Field> field = std::make_unique<Field>();

	for (int i = 0; i < fieldSize.first; i++) 
		for (int j = 0; j < fieldSize.second; j++)
			field->insert(FieldCell(Position(i, j), 
				i == 0 ? BORDER_FIELD_CHAR : 
				i == fieldSize.first - 1 ? BORDER_FIELD_CHAR : 
				j == 0 ? BORDER_FIELD_CHAR 	: 
				j == fieldSize.second - 1 ? BORDER_FIELD_CHAR : 
				FREE_SPACE_CHAR));
	return field;
}

void 
writeField(const Field& field, const FieldSize& fieldSize) {
	for (int i = 0; i < fieldSize.first;i++) {
		for (int j = 0; j < fieldSize.second;j++) {
			std::cout << field.at(Position(i, j));
		}
		std::cout << std::endl;
	}
}

void 
drawSnake(const SnakeBody& body, Field& field) {
	std::for_each(body.begin(), body.end(),
		[&](const Position& position) {field.at(position) = SNAKE_BODY_CHAR;});
	field.at(*body.begin()) = SNAKE_HEAD_CHAR;
}

void 
redrawScreen(Field& field, const Field& copyField) {
	field = copyField;
	setCarriagePos(Position(0, 0));
}

const Position 
spawnEat(const Field& field, Field& copyField, const FieldSize& fieldSize, bool& isExist) {

	static Position pos;
	if (!isExist) {
		std::vector<Position> possiblePositions;

		for (int i = 1; i < fieldSize.first - 1; i++)
			for (int j = 1; j < fieldSize.second - 1; j++)
				if ((copyField.at(Position(i, j)) == FREE_SPACE_CHAR)&&
					(field.at(Position(i, j)) == FREE_SPACE_CHAR)) 
						possiblePositions.push_back(Position(i, j));

		pos = possiblePositions[rand() % possiblePositions.size()];
		
		copyField.at(pos) = EAT_CHAR;
		isExist = 1;
	}	
	return pos;
}
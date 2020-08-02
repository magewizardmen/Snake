#include "../headers/functions.h"

char** create_field(int height, int width) {

	const char border = 'B';
	const char space = ' ';

	char** field = new char*[height];

	for (int i = 0; i < height; i++) {
		field[i] = new char[width];
		for (int j = 0; j < width; j++)
			field[i][j] = i == 0 ? border : i == height - 1 ? border : j == 0 ? border : j == width - 1 ? border : space;
	}
	return field;
}

void write_field(char** field, int height, int width) {
	for (int i = 0;i < height;i++) {
		for (int j = 0;j < width;j++)
			std::cout << field[i][j];
		std::cout << std::endl;
	}
}
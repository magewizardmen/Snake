
#include "headers\functions.h"
#include "headers\snake.h"
#include "const.h"



int main() {

	const std::pair<int, int> FIELD_SIZE(30,30); //first == height

	const int delayTime = 100;
	const int delayBeforeExit = 1000;

	Snake snake;

	auto field = createField(FIELD_SIZE);
	auto fieldCopy = *field;
	bool isExist = 0;
	int  resultOfChecking = 1;

	while(resultOfChecking)
	while (resultOfChecking) {
		snake.changeDirection();
		resultOfChecking = snake.checkCollisions(*field);
		redrawScreen(*field, fieldCopy);
		auto pos = spawnEat(*field, fieldCopy, FIELD_SIZE, isExist);

		if (snake.checkCollisions(*field) == 2) {
			fieldCopy[pos] = FREE_SPACE_CHAR;
			isExist = 0;
		}
		mySleep(delayTime);
		snake.move(snake.checkCollisions(*field));
		drawSnake(snake.getBody(), *field);

		writeField(*field, FIELD_SIZE);

		if (resultOfChecking == 0) {
			snake.changeDirection();
			auto tmp = *snake.getBody().begin();
			if (tmp.first == FIELD_SIZE.first ||
				tmp.first == 0 ||
				tmp.second == FIELD_SIZE.second ||
				tmp.second == 0) {
			}
			else
				snake.changeDirection();
		}
	}

	mySleep(delayBeforeExit);
	return 0;
}
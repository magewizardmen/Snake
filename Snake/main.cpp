
#include "headers\functions.h"
#include "headers\snake.h"

#include <iostream>



int main() {

	const std::pair<int, int> field_size(30,30); //first == height


	Snake s;

	auto field = create_field(field_size);
	auto copy_field = *field;

	while (s.check(*field)) {
		redraw_scr(*field, copy_field);
		mySleep(150);
		s.move();
		draw_snake(s.getBody(), *field);
		spawn_eat(copy_field, field_size);
		write_field(*field, field_size);
		s.change_direction();
	}
	return 0;
}
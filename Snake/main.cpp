
#include "headers\functions.h"
#include "headers\snake.h"

#include <iostream>



int main() {

	const std::pair<int, int> field_size(30,30); //first == height


	Snake s;

	auto field = create_field(field_size);
	auto copy_field = *field;
	bool is_exist = 0;

	while (s.check(*field)) {
		redraw_scr(*field, copy_field);
		auto pos = spawn_eat(copy_field, field_size, is_exist);

		if (s.check(*field) == 2) {
			copy_field[pos] = ' ';
			is_exist = 0;
		}
		mySleep(150);
		s.move(s.check(*field));
		draw_snake(s.getBody(), *field);

		write_field(*field, field_size);
		s.change_direction();
	}
	return 0;
}
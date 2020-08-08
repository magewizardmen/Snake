
#include "headers\functions.h"
#include "headers\snake.h"

#include <iostream>



int main() {

	const std::pair<int, int> field_size(30,30); //first == height


	Snake s;

	auto field = create_field(field_size);
	auto copy_field = *field;
	bool is_exist = 0;
	int check = 1;
	while(check)
	while (check) {
		s.change_direction();
		check = s.check(*field);
		redraw_scr(*field, copy_field);
		auto pos = spawn_eat(*field, copy_field, field_size, is_exist);

		if (s.check(*field) == 2) {
			copy_field[pos] = ' ';
			is_exist = 0;
		}
		mySleep(100);
		s.move(s.check(*field));
		draw_snake(s.getBody(), *field);

		write_field(*field, field_size);

		if (check == 0) {
			s.change_direction();
			auto tmp = *s.getBody().begin();
			if (tmp.first == field_size.first ||
				tmp.first == 0 ||
				tmp.second == field_size.second ||
				tmp.second == 0) {}
			else
				check = s.check(*field);
		}
	}

	mySleep(1000);
	return 0;
}

#include "headers\functions.h"
#include "headers\snake.h"

int main() {

	const std::pair<int, int> field_size(20,10); //first = height


	Snake s;

	auto field = create_field(field_size);
	auto copy_field = *field;

	while (s.check(*field)) {
		clear_scr(*field, copy_field);
		draw_snake(s.move(), *field);
		write_field(*field, field_size);
	}
	return 0;
}
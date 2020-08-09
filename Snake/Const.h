#ifndef CONST_H
#define CONST_H

const char snake_body_char = 'z';
const char snake_head_char = '@';
const char border_field_char = 'B';
const char eat_char = 'E';
const char free_space_char = ' ';



/****************NON-PORTABLE CONSTS*********************/

//controls char codes

namespace non_portable {

	const int Left = 75;
	const int Up = 72;
	const int Right = 77;
	const int Down = 80;

};
#endif
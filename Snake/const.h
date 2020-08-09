#ifndef CONST_H
#define CONST_H

const char SNAKE_BODY_CHAR = 'z';
const char SNAKE_HEAD_CHAR = '@';
const char BORDER_FIELD_CHAR = 'B';
const char EAT_CHAR = 'E';
const char FREE_SPACE_CHAR = ' ';



/****************NON-PORTABLE CONSTS*********************/

//controls char codes

namespace non_portable {

	const int LEFT = 75;
	const int UP = 72;
	const int RIGHT = 77;
	const int DOWN = 80;

};
#endif
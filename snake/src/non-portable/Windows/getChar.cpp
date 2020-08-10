#include "../../../headers/non-portable.h"

int 
getChar() {
	if (_kbhit()) {
		auto code = _getch();
		if (code == 224)
			return _getch();
		else return code;
	}
}

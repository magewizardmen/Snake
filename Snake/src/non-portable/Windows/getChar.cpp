#include "../../../headers/non-portable.h"

int getChar() {
	if (_kbhit()) {
		if (_getch() == 224)
			return _getch();
	}
}

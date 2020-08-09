
#ifndef NON_PORTABLE_H
#define NON_PORTABLE_H

#include <utility>

#include "../const.h"


#ifdef _WIN32||_WIN64||WINDOWS

#include <Windows.h>
#include <conio.h>



#else




#endif


typedef std::pair<int, int> Position;


void 
setCarriagePos(const Position&);

void 
mySleep(int);

int 
getChar();



#endif 
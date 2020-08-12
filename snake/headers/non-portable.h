
#ifndef NON_PORTABLE_H
#define NON_PORTABLE_H

#include <utility>

#include "../const.h"


#ifdef WINDOWS||_WIN32||_WIN64||_Windows||Windows||_WINDOWS||_WIN32_||_WIN64_||WIN32||WIN64||_Windows_||_WINDOWS_

#include <Windows.h>
#include <conio.h>



#else

#include <unistd.h>
#include <termios.h>
#include <fcntl.h>


#endif


typedef std::pair<int, int> Position;


void 
setCarriagePos(const Position&);

void 
mySleep(int);

int 
getChar();



#endif 

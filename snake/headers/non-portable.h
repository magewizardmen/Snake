
#ifndef NON_PORTABLE_H
#define NON_PORTABLE_H

#include <utility>

#include "../const.h"


#if defined(WINDOWS)|| defined(_WIN32) || defined(_WIN64) || defined(_Windows) || defined(Windows) || defined(_WINDOWS) || defined(_WIN32_) || defined(_WIN64_) || defined(WIN32) || defined(WIN64) || defined(_Windows_) || defined(_WINDOWS_)

#include <Windows.h>
#include <conio.h>



#else

#include <unistd.h>
#include <termios.h>
#include <iostream>
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

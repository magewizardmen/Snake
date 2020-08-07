
#ifndef NON_PORTABLE_H
#define NON_PORTABLE_H

#ifdef _WIN32||_WIN64||WINDOWS

#include <Windows.h>
#include <conio.h>



#else




#endif



void setCarriagePos(int, int);

void mySleep(int);

int getChar();



#endif 
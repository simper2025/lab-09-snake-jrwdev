#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "Point.h"

class Console {
private:
	void setcolor(WORD color);
	void gotoxy(int x, int y);
public:
	void txtPlot(point, unsigned char);
};

#endif
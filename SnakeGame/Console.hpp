#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "Windows.h"
#include "Point.h"

class Console {
private:
    static void setcolor(WORD color);
    static void gotoxy(int x, int y);
public:
    static void txtPlot(point item, unsigned char Color);
    static void setColor(WORD color);
    static void gotoXY(int x, int y);
    static void drawBorder(int width, int height);
};

#endif
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "Console.hpp"

void Console::setcolor(WORD color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Console::gotoxy(int x, int y) {
    COORD coord;
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::txtPlot(point item, unsigned char Color) {
    setcolor(Color);
    gotoxy(item.x * 2, item.y);
    _cprintf(" O ");
}

void Console::setColor(WORD color) {
    setcolor(color);
}

void Console::gotoXY(int x, int y) {
    gotoxy(x, y);
}

void Console::drawBorder(int width, int height) {
    setcolor(8);
    for (int x = 0; x < width; ++x) {
        gotoxy(x * 2, 0);
        _cprintf(" __ ");
        gotoxy(x * 2, height - 1);
        _cprintf(" __ ");
    }
    for (int y = 1; y < height - 1; ++y) {
        gotoxy(0, y);
        _cprintf(" | ");
        gotoxy((width) * 2, y);
        _cprintf(" | ");
    }
}
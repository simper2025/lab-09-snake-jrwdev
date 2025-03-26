#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Point.h"
#include "KeyCommand.h"

class Snake {
private:
	point head;
	std::vector<point> tail;
	point direction;
	int length;
	unsigned char headColor;
	unsigned char bodyColor;
public:
	Snake(unsigned char headColor, unsigned char bodyColor, point initHead, point initDirection, int initLength);
	void move(KeyCommand key);
	void grow();
	bool checkCollision(int max_x, int max_y);
	void draw();
	int getLength() const;
	point getHead() const;
};

#endif
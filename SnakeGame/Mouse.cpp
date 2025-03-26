#include "Mouse.hpp"
#include "Console.hpp"
#include <cstdlib>
#include <ctime>

Mouse::Mouse() {
	srand(time(0));
	location = { 0, 0 };
}

void Mouse::Move(int max_x, int max_y) {
	location.x = (rand() % (max_x - 1)) + 1;
	location.y = (rand() % (max_y - 1)) + 1;
}

void Mouse::draw() {
	Console console;
	console.txtPlot(location, 10);
}

point Mouse::getLocation() const {
	return location;
}
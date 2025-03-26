#include "Snake.hpp"
#include "Console.hpp"

Snake::Snake(unsigned char headColor, unsigned char bodyColor, point initHead, point initDirection, int initLength)
	: head(initHead),
	direction(initDirection),
	length(initLength),
	headColor(headColor),
	bodyColor(bodyColor)
{
	point tailPos = { head.x - initDirection.x, head.y - initDirection.y };
	for (int i = 1; i < length; i++) {
		tail.push_back(tailPos);
		tailPos.x -= initDirection.x;
		tailPos.y -= initDirection.y;
	}
}

void Snake::move(KeyCommand key) {
	if (key != KeyCommand::NONE) {
		point new_direction = direction;
		switch (key) {
		case KeyCommand::UP:
			new_direction = { 0, -1 };
			break;
		case KeyCommand::DOWN:
			new_direction = { 0, 1 };
			break;
		case KeyCommand::LEFT:
			new_direction = { -1, 0 };
			break;
		case KeyCommand::RIGHT:
			new_direction = { 1, 0 };
			break;
		default:
			break;
		}

		if (new_direction.x != -direction.x || new_direction.y != -direction.y) {
			direction = new_direction;
		}
	}

	tail.insert(tail.begin(), head);
	head.x += direction.x;
	head.y += direction.y;
	if (static_cast<int>(tail.size()) > length - 1) {
		tail.pop_back();
	}
}

void Snake::grow() {
	length++;
}

bool Snake::checkCollision(int max_x, int max_y) {
	if (head.x < 0 || head.x >= max_x || head.y < 0 || head.y >= max_y) {
		return true;
	}
	for (const auto& part:tail) {
		if (head.x == part.x && head.y == part.y) {
			return true;
		}
	}
	return false;
}

void Snake::draw() {
	Console console;
	console.txtPlot(head, headColor);
	for (const auto& part : tail) {
		console.txtPlot(part, bodyColor);
	}
}

int Snake::getLength() const {
	return length;
}

point Snake::getHead() const {
	return head;
}
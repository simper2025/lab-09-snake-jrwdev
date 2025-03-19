#ifndef GAMERUNNER_HPP
#define GAMERUNNER_HPP

#include "Keyboard.hpp"
#include "Keycommand.h"
#include "Snake.hpp"
#include "Mouse.hpp"

class GameRunner {
private:
	float frame_duration;
	Keyboard keyboard;
	KeyCommand keypress;
	Snake snake;
	Mouse mouse;

public:
	GameRunner(float fps);
	void RunGame();
};

#endif
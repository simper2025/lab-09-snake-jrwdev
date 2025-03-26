#ifndef GAMERUNNER_HPP
#define GAMERUNNER_HPP

#include "Keyboard.hpp"
#include "Keycommand.h"
#include "Snake.hpp"
#include "Mouse.hpp"

class GameRunner {
private:
	const int WIDTH = 20;
	const int HEIGHT = 20;
	float frame_duration;
	Keyboard keyboard;
	KeyCommand keypress;
	Snake snake;
	Mouse mouse;
	bool game_over;

public:
	GameRunner(float fps);
	void RunGame();
};

#endif
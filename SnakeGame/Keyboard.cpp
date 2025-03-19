#include <conio.h>
#include "Keyboard.hpp"

KeyCommand Keyboard::get_key() {
	static char key;
	static KeyCommand key_command = KeyCommand::RIGHT;

	if (_kbhit()) {
		key = _getch();
		if (key == -32 || key == 224 || key == 0) {
			key = _getch();
			switch (key) {
			case key_UP:
				key_command = KeyCommand::UP;
				break;
			case key_DOWN:
				key_command = KeyCommand::DOWN;
				break;
			case key_LEFT:
				key_command = KeyCommand::LEFT;
				break;
			case key_RIGHT:
				key_command = KeyCommand::RIGHT;
				break;
			case key_ESCAPE:
				key_command = KeyCommand::QUIT;
				break;
			default:
				break;
			}
		}
		else {
			switch (key) {
			case 'w':
			case 'W':
				key_command = KeyCommand::UP;
				break;
			case 's':
			case 'S':
				key_command = KeyCommand::DOWN;
				break;
			case 'a':
			case 'A':
				key_command = KeyCommand::LEFT;
				break;
			case 'd':
			case 'D':
				key_command = KeyCommand::RIGHT;
				break;
			case key_ESCAPE:
				key_command = KeyCommand::QUIT;
				break;
			default:
				break;
			}
		}
	}
	return key_command;
}
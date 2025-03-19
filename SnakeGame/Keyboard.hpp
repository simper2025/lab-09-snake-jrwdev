#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "KeyCommand.h"

#define key_UP 72
#define key_DOWN 80
#define key_LEFT 75
#define key_RIGHT 77
#define key_ESCAPE 27

class Keyboard {
private:
public:
	KeyCommand get_key();
};

#endif
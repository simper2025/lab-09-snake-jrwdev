#ifndef MOUSE_HPP
#define MOUSE_HPP

class Mouse {
private:
	point location;
public:
	Mouse();
	void Move(int max_x, int max_y);
	void draw();
	point getLocation() const;
};

#endif
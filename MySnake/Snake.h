#pragma once
#include "Entity.h"


class Snake : public Entity {
private:

public:
	void move_up();
	void move_down();
	void move_left();
	void move_right();
};


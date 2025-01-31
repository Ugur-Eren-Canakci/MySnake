#pragma once
#include "Entity.h"


class Wall : public Entity {
private:
	static sf::Texture texture;
	sf::Sprite sprite;
};


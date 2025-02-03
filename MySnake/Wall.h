#pragma once
#include "Entity.h"


class Wall : public Entity {
private:
	static sf::Texture texture;
	sf::Sprite sprite;
public:
	Wall();

	Wall(float x, float y);

	sf::Sprite get_sprite() const {
		return sprite;
	}

};


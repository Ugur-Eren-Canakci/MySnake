#pragma once
#include "Entity.h"


class Wall : public Entity {
private:
	static sf::Texture texture;
	sf::Sprite sprite;
public:
	// constructors
	Wall();
	Wall(float x, float y);

	// helper functions
	sf::Sprite get_sprite() const {
		return sprite;
	}

	float get_x() const {
		return sprite.getPosition().x;
	}
	float get_y() const {
		return sprite.getPosition().y;
	}
};


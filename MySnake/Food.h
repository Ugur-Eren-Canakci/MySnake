#pragma once

#include "Entity.h"
#include "constants.h"

class Food : public Entity {
private:
	static sf::Texture texture;
	sf::Sprite sprite;
public: 
	Food();
	Food(int x, int y);
	~Food();

	sf::Sprite get_sprite() const noexcept {
		return this->sprite;
	}

	int get_x() const noexcept {
		return int(sprite.getPosition().x);
	}

	int get_y() const noexcept {
		return (sprite.getPosition().y);
	}

};


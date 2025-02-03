#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "constants.h"

class Food : public Entity {
private:
	static sf::Texture texture;
	sf::Sprite sprite;
public: 
	Food();
	Food(float x, float y);
	Food(sf::Vector2f location);
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

	void setPosition(sf::Vector2f location) {
		sprite.setPosition(location);
	}
};


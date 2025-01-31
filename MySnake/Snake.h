#pragma once

#include "Entity.h"
#include "Food.h"

#include <cmath>
#include <vector>
#include <iostream>

enum class Direction {UP, DOWN, LEFT, RIGHT};

class snakeHead {
private:
	static sf::Texture texture;
	sf::Sprite sprite;
public:

	snakeHead() : sprite(texture) {}

	sf::Sprite get_sprite() const {
		return this->sprite;
	}

	void setPosition(float x, float y) {
		sprite.setPosition(sf::Vector2f{ x,y });
	}

	float get_x() const {
		return sprite.getPosition().x;
	}

	float get_y() const {
		return sprite.getPosition().y;
	}
};

class snakeBody {
private:
	static sf::Texture texture;
	sf::Sprite sprite;
public:

	snakeBody() : sprite(texture) {}

	sf::Sprite get_sprite() const {
		return this->sprite;
	}

	void setPosition(float x, float y) {
		sprite.setPosition(sf::Vector2f{ x,y });
	}

	float get_x() const {
		return sprite.getPosition().x;
	}

	float get_y() const {
		return sprite.getPosition().y;
	}
};

class Snake : public Entity {
private:
	
	snakeHead head;
	Direction head_direction;
	std::vector<snakeBody> body;
	
public:

	Snake();
	
	sf::Sprite get_head_sprite() {
		return head.get_sprite();
	}

	std::vector<snakeBody>& get_body_parts() {
		return body;
	}

	void setPosition(int x, int y);

	void move_up();
	void move_down();
	void move_left();
	void move_right();

	bool ate_the_food(const Food& food) const {
		bool horizontal = std::abs(head.get_x() - food.get_x()) < 4*constants::move_distance;
		bool vertical = std::abs(head.get_y() - food.get_y()) < 4*constants::move_distance;
		return horizontal && vertical;
	}

	bool ate_itself(const snakeBody& body) const {
		bool horizontal = std::abs(head.get_x() - body.get_x()) < 4 * constants::move_distance;
		bool vertical = std::abs(head.get_y() - body.get_y()) < 4 * constants::move_distance;
		return horizontal && vertical;

	}
};


#pragma once

#include "Entity.h"
#include "Food.h"
#include "Wall.h"

#include <cmath>
#include <vector>
#include <iostream>
#include <memory>

enum class Direction {UP, DOWN, LEFT, RIGHT};

class snakeHead {
private:
	static sf::Texture texture;
	sf::Sprite sprite;
	Direction direction;
public:

	snakeHead() : sprite(texture), direction(Direction::RIGHT) {}

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

	Direction get_direction() const {
		return direction;
	}

	void set_direction(Direction d) {
		direction = d;
	}
};

class snakeBody {
private:
	static sf::Texture texture;
	sf::Sprite sprite;
	Direction direction;
public:

	snakeBody() : sprite(texture), direction(Direction::RIGHT) {}

	snakeBody(float x, float y) : sprite(texture), direction(Direction::RIGHT) {
		sprite.setPosition({ x,y });
	}

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

	Direction get_direction() const {
		return direction;
	}

	void set_direction(Direction d) {
		direction = d;
	}

};

class Snake : public Entity {
private:
	snakeHead head;
	std::vector<snakeBody> body;
public:

	// constructor
	Snake();

	// body parts
	sf::Sprite get_head_sprite() {
		return head.get_sprite();
	}
	std::vector<snakeBody>& get_body_parts() {
		return body;
	}
	void setPosition(int x, int y);
	void add_body_part();
	
	// movements
	void move_up();
	void move_down();
	void move_left();
	void move_right();

	// interactions with elements
	bool ate_the_food(const Food& food) const;
	bool crashed_itself(const snakeBody& body) const;
	bool crashed_a_wall(const Wall& wall) const;
};


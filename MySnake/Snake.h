#pragma once

#include "Entity.h"
#include "Food.h"

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

	Snake();
	
	sf::Sprite get_head_sprite() {
		return head.get_sprite();
	}

	std::vector<snakeBody>& get_body_parts() {
		return body;
	}

	void setPosition(int x, int y);

	void add_body_part() {
		snakeBody new_body{};
		auto last_body = body[body.size() - 1];
		if (head.get_direction() == Direction::UP) {
			new_body.setPosition(last_body.get_sprite().getPosition().x,
								 last_body.get_sprite().getPosition().y - constants::move_distance);
		}
		else if (head.get_direction() == Direction::DOWN) {
			new_body.setPosition(last_body.get_sprite().getPosition().x,
								 last_body.get_sprite().getPosition().y + constants::move_distance);
		}
		else if (head.get_direction() == Direction::LEFT) {
			new_body.setPosition(last_body.get_sprite().getPosition().x + constants::move_distance,
								 last_body.get_sprite().getPosition().y );
		}
		else {
			new_body.setPosition(last_body.get_sprite().getPosition().x - constants::move_distance,
				last_body.get_sprite().getPosition().y);
		}

		body.push_back(new_body);


	}

	void move_up();
	void move_down();
	void move_left();
	void move_right();

	bool ate_the_food(const Food& food) const {
		bool horizontal = std::abs(head.get_x() - food.get_x()) < constants::snake_head_size;
		bool vertical = std::abs(head.get_y() - food.get_y()) < constants::snake_head_size;
		return horizontal && vertical;
	}

	bool ate_itself(const snakeBody& body) const {
		bool horizontal = std::abs(head.get_x() - body.get_x()) < constants::move_distance;
		bool vertical = std::abs(head.get_y() - body.get_y()) <  constants::move_distance;
		return horizontal && vertical;

	}
};


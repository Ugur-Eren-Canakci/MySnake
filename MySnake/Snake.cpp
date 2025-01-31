#include <iostream>

#include "Snake.h"
#include "constants.h"

sf::Texture snakeHead::texture("../images/snake_green_head_64.png");
sf::Texture snakeBody::texture("../images/snake_green_blob_64.png");

Snake::Snake() : head(), body(3), head_direction(Direction::RIGHT) {

	head.setPosition( 0.0f, 0.0f );
	for (int i = 0; i < body.size(); i++) {
		body[i].setPosition(
			head.get_x() - (i+1) * constants::snake_body_size,
			head.get_y());
	}
}

void Snake::setPosition(int x, int y) {
	for (int i = body.size() - 1; i >0; i--) {
		body[i].setPosition(body[i - 1].get_x(), body[i - 1].get_y());
	}
	body[0].setPosition(head.get_x(), head.get_y());
	head.setPosition(1.0 * x, 1.0 * y);
}

void Snake::move_up() {
	if (head_direction != Direction::DOWN) {
		head_direction = Direction::UP;
		setPosition(
			head.get_x(),
			head.get_y() - constants::move_distance);
	}
	
}

void Snake::move_down() {
	if (head_direction != Direction::UP) {
		head_direction = Direction::DOWN;
		setPosition(
			head.get_x(),
			head.get_y() + constants::move_distance);
	}
}

void Snake::move_left() {
	if (head_direction != Direction::RIGHT) {
		head_direction = Direction::LEFT;
		setPosition(
			head.get_x() - constants::move_distance,
			head.get_y());
	}
}

void Snake::move_right() {
	if (head_direction != Direction::LEFT) {
		head_direction = Direction::RIGHT;
		setPosition(
			head.get_x() + constants::move_distance,
			head.get_y());
	}

}


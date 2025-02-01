#include <iostream>

#include "Snake.h"
#include "constants.h"

sf::Texture snakeHead::texture("C:/Users/ugur_/Desktop/git repos/MySnake/MySnake/images/snake_green_head_32.png");
sf::Texture snakeBody::texture("C:/Users/ugur_/Desktop/git repos/MySnake/MySnake/images/snake_green_blob_32.png");

Snake::Snake() : head() {

	std::vector<snakeBody> temp;
	head.setPosition( 0.0f, 0.0f );
	for (int i = 0; i < constants::start_body_length; i++) {
		temp.push_back(snakeBody{head.get_x() - (i + 1) * constants::snake_body_size,
								 head.get_y() }
					  );
	}
	body = temp;
}

void Snake::setPosition(int x, int y) {
	
	for (int i = body.size() - 1; i > 0; i--) {
		float new_x = body[i - 1].get_x();
		float new_y = body[i - 1].get_y();
		body[i].setPosition(new_x, new_y);
	}
	body[0].setPosition(head.get_x(), head.get_y());
	
	
	head.setPosition(1.0 * x, 1.0 * y);

}

void Snake::move_up() {
	if (head.get_direction()!= Direction::DOWN) {
		head.set_direction(Direction::UP);
		setPosition(
			head.get_x(),
			head.get_y() - constants::move_distance);

	}
	
}

void Snake::move_down() {
	if (head.get_direction() != Direction::UP) {
		head.set_direction(Direction::DOWN);
		setPosition(
			head.get_x(),
			head.get_y() + constants::move_distance);
	}
}

void Snake::move_left() {
	if (head.get_direction() != Direction::RIGHT) {
		head.set_direction(Direction::LEFT);
		setPosition(
			head.get_x() - constants::move_distance,
			head.get_y());
	}
}

void Snake::move_right() {
	if (head.get_direction() != Direction::LEFT) {
		head.set_direction(Direction::RIGHT);
		setPosition(
			head.get_x() + constants::move_distance,
			head.get_y());
	}

}


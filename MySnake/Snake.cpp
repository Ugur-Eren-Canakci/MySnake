#include <iostream>
#include <cmath>


#include "Snake.h"
#include "constants.h"

sf::Texture snakeHead::texture("C:/Users/ugur_/Desktop/git repos/MySnake/MySnake/images/snake_green_head_32.png");
sf::Texture snakeBody::texture("C:/Users/ugur_/Desktop/git repos/MySnake/MySnake/images/snake_green_blob_32.png");

// default constructor
Snake::Snake() : head() {

	std::vector<snakeBody> temp;
	head.setPosition((constants::window_width - constants::snake_head_size) / 2, 
					 (constants::window_height - constants::snake_head_size) / 2);
	for (int i = 0; i < constants::start_body_length; i++) {
		temp.push_back(snakeBody{head.get_x(),
								 head.get_y() + (i + 1) * constants::move_distance }
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

void Snake::add_body_part() {
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
			last_body.get_sprite().getPosition().y);
	}
	else {
		new_body.setPosition(last_body.get_sprite().getPosition().x - constants::move_distance,
			last_body.get_sprite().getPosition().y);
	}

	body.push_back(new_body);
}

// movements
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

// interactions with elements
bool Snake::ate_the_food(const Food& food) const {
	bool horizontal = std::abs(head.get_x() - food.get_x()) < constants::snake_head_size;
	bool vertical = std::abs(head.get_y() - food.get_y()) < constants::snake_head_size;
	return horizontal && vertical;
}

bool Snake::crashed_itself(const snakeBody& body) const {
	bool horizontal = std::abs(head.get_x() - body.get_x()) < constants::move_distance;
	bool vertical = std::abs(head.get_y() - body.get_y()) < constants::move_distance;
	return horizontal && vertical;
}

bool Snake::crashed_a_wall(const Wall& wall) const {
	bool horizontal = std::abs(head.get_x() - wall.get_x()) < constants::snake_head_size;
	bool vertical = std::abs(head.get_y() - wall.get_y()) < constants::snake_head_size;
	return horizontal && vertical;
}

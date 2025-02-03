#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include <vector>
#include <chrono>

#include "Game_Manager.h"
#include "constants.h"
#include "Food.h"
#include "Snake.h"
#include "Wall.h"

std::vector<Wall> generate_outer_walls() {
	
	std::vector<Wall> outer_walls;
	// number of horizontal walls
	int horizontal_wall_count = constants::window_width / constants::wall_side_length;
	int vertical_wall_count = constants::window_height / constants::wall_side_length;

	// top layer
	for (int i = 0; i < horizontal_wall_count; i++) {
		outer_walls.push_back(Wall{ i * constants::wall_side_length, 0 });
	}

	// bottom layer
	for (int i = 0; i < horizontal_wall_count; i++) {
		outer_walls.push_back(Wall{ i * constants::wall_side_length, constants::window_height - constants::wall_side_length });
	}

	// left layer
	for (int i = 1; i < vertical_wall_count-1; i++) {
		outer_walls.push_back(Wall{ 0, i*constants::wall_side_length });
	}

	// right layer
	for (int i = 1; i < vertical_wall_count-1; i++) {
		outer_walls.push_back(Wall{ constants::window_width - constants::wall_side_length, i *constants::wall_side_length });
	}

	return outer_walls;
}

using namespace std::literals;

// overlays
game_start_overlay Game_Manager::start_overlay;
game_play_overlay Game_Manager::play_overlay;
game_over_overlay Game_Manager::over_overlay;

// rng
std::mt19937 Game_Manager::rng;
std::uniform_int_distribution<int> Game_Manager::horizontal_placement{ int(constants::wall_side_length) + 1, 
																	   int(constants::window_width - constants::wall_side_length - constants::food_length)};
std::uniform_int_distribution<int> Game_Manager::vertical_placement{ int(constants::wall_side_length) + 1, 
																	 int(constants::window_width - constants::wall_side_length - constants::food_length) };

// timer 
std::chrono::steady_clock Game_Manager::timer;

Game_Manager::Game_Manager() :
	// game window initialized here for now, maybe I'll change it
	game_window(
		sf::VideoMode({ constants::window_width,constants::window_height }),
		"My Snake"
	),
	game_state{ GAME_STATE::START },
	snake{},
	outer_walls{ generate_outer_walls() }
{
	// set framerate limit
	game_window.setFramerateLimit(60);

	// generate apple on non-occupied space
	apple.setPosition(get_new_position());
}

std::vector<std::pair<sf::Vector2f, sf::Vector2f>> Game_Manager::object_locations() {

	std::vector<std::pair<sf::Vector2f, sf::Vector2f> > result;
	// snake head location
	result.push_back({ snake.get_head_sprite().getGlobalBounds().position, snake.get_head_sprite().getGlobalBounds().size });
	// snake body parts locations
	for (const auto& el : snake.get_body_parts()) {
		result.push_back({ el.get_sprite().getGlobalBounds().position,el.get_sprite().getGlobalBounds().size });
	}
	// return the whole vector
	return result;
}

void Game_Manager::get_start_input() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::P)) {
		game_state = GAME_STATE::RUN;
	}
}
void Game_Manager::get_game_input() {
	// controls
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
		snake.move_up();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
		snake.move_down();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
		snake.move_left();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
		snake.move_right();
	}
}
void Game_Manager::get_closing_input() {

	while (const std::optional event = game_window.pollEvent()) {

		if (event->is<sf::Event::Closed>()) {
			game_window.close();
		}

		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {

			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				game_window.close();

			else if (keyPressed->scancode == sf::Keyboard::Scancode::Q)
				game_window.close();
		}
	}

}
void Game_Manager::get_game_over_inputs() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::R)) {
		play_overlay.reset_score();
		snake = Snake{};
		apple = Food{get_new_position()};
		game_state = GAME_STATE::RUN;
	}
}

void Game_Manager::update_screen() {
	game_window.display();
}

sf::Vector2f Game_Manager::get_new_position() {
	// generate a position
	sf::Vector2f new_position{ float(horizontal_placement(rng)), float(vertical_placement(rng)) };

	// get all occupied places and compare 
	auto locations = object_locations();
	auto it = locations.begin();
	while (it != locations.end()) {
		float left_bound = it->first.x;
		float right_bound = it->first.x + it->second.x;
		float upper_bound = it->first.y;
		float lower_bound = it->first.y + it->second.y;

		if ( (new_position.x >= left_bound && new_position.x <= right_bound) || (new_position.y >= upper_bound && new_position.y <= lower_bound) ) {
			new_position = sf::Vector2f{ float(horizontal_placement(rng)),float(vertical_placement(rng)) };
			it = locations.begin();
		}
		else {
			it++;
		}
	}

	// when out of the loop, we have found a place where no other object is present
	// return that position
	return new_position;
}

void Game_Manager::start_screen_loop() {
	start_overlay.show_text(game_window);
	get_start_input();
}

void Game_Manager::game_screen_loop() {
	// input 
	get_game_input();

	// frame starting time
	auto frame_start = timer.now();
	// ate food
	if (snake.ate_the_food(apple)) {
		// increase snake body length
		snake.add_body_part();
		// create new apple
		// we need to place the apple onto somewhere with no other elements
		apple = Food{ get_new_position() };
		// show new score
		play_overlay.increase_score();
		// draw the score 
		play_overlay.show_text(game_window);
	}

	// ate itself
	auto body_parts = snake.get_body_parts();
	for (const auto& el : body_parts) {
		if (snake.crashed_itself(el)) {
			game_state = GAME_STATE::GAME_OVER;
		}
	}

	// crashed a wall
	for (const auto& el : outer_walls) {
		if (snake.crashed_a_wall(el)) {
			game_state = GAME_STATE::GAME_OVER;
		}
	}

	// draw the snake
	for (int i = body_parts.size() - 1; i > -1; i--) {
		game_window.draw(body_parts[i].get_sprite());
	}
	game_window.draw(snake.get_head_sprite());

	// draw the outer walls
	for (const Wall& wall : outer_walls) {
		game_window.draw(wall.get_sprite());
	}

	// draw the apple
	game_window.draw(apple.get_sprite());

	// show game score
	play_overlay.show_text(game_window);
	
	
	auto frame_end = timer.now();
	while (frame_end - frame_start < 30ms) {
		frame_end = timer.now();
		// frame is stunted until 30ms passes
	}
	

}

void Game_Manager::game_over_screen_loop() {
	over_overlay.show_text(game_window);
	get_game_over_inputs();
}

void Game_Manager::game_loop() {
	while (game_window.isOpen()) {
		// clear screen once
		game_window.clear();

		// game closing commands
		get_closing_input();

		// start screen
		if (game_state == GAME_STATE::START)
			start_screen_loop();

		// gameplay loop
		else if (game_state == GAME_STATE::RUN) {
			reset_timer();
			game_screen_loop();
		}
			
		// end of game loop
		else if (game_state == GAME_STATE::GAME_OVER)
			game_over_screen_loop();

		game_window.display();
	}
}

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

using namespace std::literals;

game_start_overlay Game_Manager::start_overlay;
game_play_overlay Game_Manager::play_overlay;
game_over_overlay Game_Manager::over_overlay;

std::mt19937 Game_Manager::rng;
std::uniform_int_distribution<int> Game_Manager::horizontal_placement{ 0, int(constants::window_width / constants::move_distance) - 1 };
std::uniform_int_distribution<int> Game_Manager::vertical_placement{ 0, int(constants::window_height / constants::move_distance) - 1 };
std::chrono::steady_clock Game_Manager::timer;

Game_Manager::Game_Manager() :
	// game window initialized here for now, maybe I'll change it
	game_window(
		sf::VideoMode({ constants::window_width,constants::window_height }), 
		"My Snake"
	), 
	game_state{ GAME_STATE::START }, 
	game_score{ 0 },
	apple{ horizontal_placement(rng), vertical_placement(rng) },
	snake{}
{
	game_window.setFramerateLimit(60);
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

void Game_Manager::update_screen() {
	game_window.display();
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

void Game_Manager::start_screen_loop() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::P)) {
		game_state = GAME_STATE::RUN;
	}

	start_overlay.show_text(game_window);
}

void Game_Manager::game_screen_loop() {

	get_game_input();

	// ate food
	if (snake.ate_the_food(apple)) {

		// create new apple
		apple = Food(horizontal_placement(rng), vertical_placement(rng));
		// increase snake body length
		snake.add_body_part();
		// show new score
		play_overlay.increase_score();
		// draw the score 
		play_overlay.show_text(game_window);
	}

	// ate itself
	auto body_parts = snake.get_body_parts();
	for (const auto& el : body_parts) {
		if (snake.ate_itself(el)) {
			game_state = GAME_STATE::GAME_OVER;
		}
	}

	// draw the apple
	game_window.draw(apple.get_sprite());

	// draw the snake
	for (int i = body_parts.size() - 1; i > -1; i--) {
		game_window.draw(body_parts[i].get_sprite());
	}
	game_window.draw(snake.get_head_sprite());

	// show game score
	play_overlay.show_text(game_window);
	
	/*
	to be added back later
		auto frame_end = timer.now();
	while (frame_end - frame_start < 30ms) {
		frame_end = timer.now();
	}
	*/

}

void Game_Manager::game_over_screen_loop() {
	over_overlay.show_text(game_window);
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
		else if (game_state == GAME_STATE::RUN)
			game_screen_loop();

		// end of game loop
		else if (game_state == GAME_STATE::GAME_OVER)
			game_over_screen_loop();

		game_window.display();
	}
}

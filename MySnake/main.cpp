#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include <vector>
#include <chrono>

#include "constants.h"
#include "Food.h"
#include "Snake.h"
#include "game_over_screen.h"
#include "game_play_screen.h"
#include "game_start_screen.h"
#include "Game_Manager.h"

using namespace std::literals;

static std::mt19937 rng;
static std::uniform_int_distribution<int> horizontal_placement{ 0, int(constants::window_width / constants::move_distance)-1 };
static std::uniform_int_distribution<int> vertical_placement{ 0, int(constants::window_height / constants::move_distance)-1 };
static std::chrono::steady_clock timer;

int main() {

	Game_Manager game_manager;

	while (true) game_manager.update_screen();
	/*
	bool game_start = false;
	bool game_over = false;
	
	sf::RenderWindow game_window(sf::VideoMode({ constants::window_width,constants::window_height }), "My Snake");
	game_window.setFramerateLimit(60);

	Food apple(horizontal_placement(rng), vertical_placement(rng));
	Snake snake{};
	auto starting_time = timer.now();
	// initialize game play screen 
	game_play_screen play_screen{};

	
	while (game_window.isOpen()) {
		
		while (!game_start) {

			game_window.clear(sf::Color::Black);
			game_start_screen start_screen{};

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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::P)) {
				game_start = true;
			}

			start_screen.show_text(game_window);
			game_window.display();

		}

		game_window.clear(sf::Color::Black);
		auto frame_start = timer.now();

		// game closing commands
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

		// gameplay loop
		if (!game_over) {

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

			
			// show current score
			play_screen.show_text(game_window);

			// ate food
			if (snake.ate_the_food(apple)) {

				// create new apple
				apple = Food(horizontal_placement(rng), vertical_placement(rng));
				// increase snake body length
				snake.add_body_part();
				// show new score
				play_screen.increase_score();
				// draw the score 
				play_screen.show_text(game_window);
				

			}

			// ate itself
			auto body_parts = snake.get_body_parts();
			for (const auto& el : body_parts) {
				if (snake.ate_itself(el)) {
					game_over = true;
				}
			}


			// draw the apple
			game_window.draw(apple.get_sprite());

			// place the snake
			for (int i = body_parts.size() - 1; i > -1; i--) {
				game_window.draw(body_parts[i].get_sprite());
			}
			game_window.draw(snake.get_head_sprite());

			// display all items
			game_window.display();

			// timer 
			// currently, movement is very simple, as in every body part is placed onto the next body part's old position, 
			// and the first body part is placed onto the head's old position.
			// drawings always sit on top of each other, which is an issue to be fixed in the future

			auto frame_end = timer.now();
			while (frame_end - frame_start < 30ms) {
				frame_end = timer.now();
			}
		}
		else {
			game_window.clear(sf::Color::Black);
			game_over_screen game_over{};
			game_over.show_text(game_window);

			game_window.display();
		}
	}
	*/



	return 0;
}
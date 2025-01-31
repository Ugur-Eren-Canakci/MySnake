#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include <vector>

#include "constants.h"
#include "Food.h"
#include "Snake.h"


static std::mt19937 rng;
static std::uniform_int_distribution horizontal_placement{ 0, int(constants::window_width / constants::move_distance)-1 };
static std::uniform_int_distribution vertical_placement{ 0, int(constants::window_height / constants::move_distance)-1 };

int main() {

	sf::RenderWindow game_window(sf::VideoMode({ constants::window_width,constants::window_height }), "My Snake");

	game_window.setFramerateLimit(60);

	int game_score = 0;

	Food apple(horizontal_placement(rng), vertical_placement(rng));
	Snake snake{};

	while (game_window.isOpen()) {
		
		game_window.clear(sf::Color::Black);

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

		if (snake.ate_the_food(apple)) {
			apple = Food(horizontal_placement(rng), vertical_placement(rng));
			game_score += 10;
		}

		// place the apple
		game_window.draw(apple.get_sprite());
		
		// place the snake
		game_window.draw(snake.get_head_sprite());
		for (const auto& el : snake.get_body_parts()) {
			game_window.draw(el.get_sprite());
		}
		
		game_window.display();
	}

	return 0;
}
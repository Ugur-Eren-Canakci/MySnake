#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "constants.h"

int max_scores[3];

static std::mt19937 rng;
static std::uniform_int_distribution;

int main() {

	sf::RenderWindow game_window(sf::VideoMode({ constants::window_width,constants::window_height }), "My Snake");
	bool game_on = false;

	game_window.setFramerateLimit(60);

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



	}

	return 0;
}
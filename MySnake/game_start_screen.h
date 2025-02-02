#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"


class game_start_screen {
private:
	sf::Font font{ "C:\\Windows\\Fonts\\arial.ttf" };
	sf::Text game_start_text{ font };
public:

	game_start_screen() {
		game_start_text.setCharacterSize(24);
		game_start_text.setFillColor(sf::Color::Red);
		game_start_text.setStyle(sf::Text::Bold);
		game_start_text.setString("Welcome to my Snake game!\nPress P to start.");
		game_start_text.setOrigin({ -constants::window_width/2,-constants::window_width / 2 });
	}

	void show_text(sf::RenderWindow& game_window) {
		game_window.draw(game_start_text);
	}
};
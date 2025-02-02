#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "screen.h"

class game_start_overlay : public overlay{
private:
	sf::Font font{ "C:\\Windows\\Fonts\\arial.ttf" };
	sf::Text game_start_text{ font };
public:

	game_start_overlay() {
		game_start_text.setCharacterSize(24);
		game_start_text.setFillColor(sf::Color::Red);
		game_start_text.setStyle(sf::Text::Bold);
		game_start_text.setString("Welcome to my Snake game!\nPress P to start.");
		game_start_text.setOrigin({ -constants::window_width / 2 + 50,
									-constants::window_height / 2 + 50});
	}

	void show_text(sf::RenderWindow& game_window) override{
		game_window.draw(game_start_text);
	}
};
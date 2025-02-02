#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "screen.h"

class game_over_screen : public screen{
private:
	sf::Font font{ "C:\\Windows\\Fonts\\arial.ttf" };
	sf::Text game_over_text{ font };
	

public: 

	game_over_screen() {
		game_over_text.setCharacterSize(24);
		game_over_text.setFillColor(sf::Color::Red);
		game_over_text.setStyle(sf::Text::Bold);
		game_over_text.setString("Game over.");
		game_over_text.setOrigin({ (-1*constants::window_width/2),
								   (-1*constants::window_height/2 ) });
		
	}

	void show_text(sf::RenderWindow& window) override {
		window.draw(game_over_text);
	}
};


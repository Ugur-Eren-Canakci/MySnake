#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"


class game_over_screen {
private:
	sf::Font font{ "C:\\Windows\\Fonts\\arial.ttf" };
	sf::Text text{ font };
	

public: 

	game_over_screen(sf::RenderWindow& game_window) {
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold);
		text.setString("Game over.");
		text.setOrigin({ (-1*constants::window_width/2), 
						 (-1*constants::window_height/2 ) });
		
		game_window.draw(text);
		game_window.display();
	}
};


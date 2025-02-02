#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class game_play_screen {
private:
	sf::Font font{ "C:\\Windows\\Fonts\\arial.ttf" };
	sf::Text score_text{ font };
	int current_score;

public:

	game_play_screen(sf::RenderWindow game_window) {
		score_text.setCharacterSize(24);
		score_text.setFillColor(sf::Color::Red);
		score_text.setStyle(sf::Text::Bold);
		score_text.setString("Current Score: 0");
		score_text.setOrigin({ 0.0f, 0.0f });

		game_window.draw(score_text);
		game_window.display();
	}

	void set_score(int score) {
		current_score = score;
		score_text.setString("Current Score: " + std::to_string(current_score));
	}

};


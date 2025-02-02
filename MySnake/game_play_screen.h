#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "screen.h"

class game_play_screen : public screen{
private:
	sf::Text score_text;
	int current_score;

public:

	game_play_screen() : score_text{ font }, current_score{ 0 } {
		score_text.setCharacterSize(24);
		score_text.setFillColor(sf::Color::Red);
		score_text.setStyle(sf::Text::Bold);
		score_text.setString("Current Score: 0");
		score_text.setOrigin({ 0.0f, 0.0f });

	}
	
	void show_text(sf::RenderWindow& window) override {
		score_text.setString("Current Score: " + std::to_string(current_score));
		window.draw(score_text);
	}

	void increase_score() {
		current_score += 10;
	}
};


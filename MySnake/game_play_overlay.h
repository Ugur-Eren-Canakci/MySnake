#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "screen.h"
#include "Snake.h"

class game_play_overlay : public overlay{
private:
	sf::Text score_text;
	sf::Text timer_text;
	int current_score;
public:

	game_play_overlay() : score_text{ font }, timer_text{ font }, current_score { 0 } {
		score_text.setCharacterSize(24);
		score_text.setFillColor(sf::Color::Red);
		score_text.setStyle(sf::Text::Bold);
		score_text.setString("Current Score: 0");
		score_text.setOrigin({ 0.0f, 0.0f });

		timer_text.setCharacterSize(24);
		timer_text.setFillColor(sf::Color::Red);
		timer_text.setStyle(sf::Text::Bold);
		timer_text.setString("Play Duration: 0");
		timer_text.setOrigin({ 0.0f, 24.0f });
	}
	
	void show_text(sf::RenderWindow& window) override {
		score_text.setString("Current Score: " + std::to_string(current_score));
		window.draw(score_text);
	}


	int get_score() const {
		return current_score;
	}

	void increase_score() {
		current_score += 10;
	}

	void reset_score() {
		current_score = 0;
	}
};


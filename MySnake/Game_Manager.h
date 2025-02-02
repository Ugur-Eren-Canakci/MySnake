#pragma once

#include <SFML/Graphics.hpp>
#include "game_start_screen.h"
#include "game_play_screen.h"
#include "game_over_screen.h"


enum class GAME_STATE {START, RUN, GAME_OVER};


class Game_Manager {
private:

	// RNG
	static std::mt19937 rng;
	static std::uniform_int_distribution<int> horizontal_placement;
	static std::uniform_int_distribution<int> vertical_placement;
	
	// timer
	static std::chrono::steady_clock timer;
	
	// game screens
	static game_start_screen start_screen;
	static game_play_screen play_screen;
	static game_over_screen over_screen;
	
	// game window
	sf::RenderWindow game_window;

	// game attributes
	int game_score = 0;
	bool game_start = false;
	bool game_over = false;
	GAME_STATE game_state;
public:
	Game_Manager();

	void update_screen();
	void show_start_screen();
	void show_game_screen();
	void show_game_over_screen();

};
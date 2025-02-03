#pragma once

#include <SFML/Graphics.hpp>
#include "game_start_overlay.h"
#include "game_play_overlay.h"
#include "game_over_overlay.h"
#include "Snake.h"

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
	static game_start_overlay start_overlay;
	static game_play_overlay play_overlay;
	static game_over_overlay over_overlay;
	
	// game window
	sf::RenderWindow game_window;

	// game attributes
	int game_score = 0;
	GAME_STATE game_state;

	// snake
	Snake snake;

	// food
	Food apple;

public:
	// default constructor
	Game_Manager();

	// updating the screen
	void update_screen();

	// inputs
	void get_start_input();
	void get_game_input();
	void get_closing_input();
	void get_game_over_inputs();

	// loops in each game mode
	void start_screen_loop();
	void game_screen_loop();
	void game_over_screen_loop();

	// main controler of the game loop
	void game_loop();
};
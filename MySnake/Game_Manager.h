#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "game_start_overlay.h"
#include "game_play_overlay.h"
#include "game_over_overlay.h"
#include "Snake.h"
#include "Wall.h"

enum class GAME_STATE {START, RUN, GAME_OVER};

class Game_Manager {
private:

	// game window
	sf::RenderWindow game_window;

	// rng
	static std::mt19937 rng;
	static std::uniform_int_distribution<int> horizontal_placement;
	static std::uniform_int_distribution<int> vertical_placement;
	
	// overlay objects
	static game_start_overlay start_overlay;
	static game_play_overlay play_overlay;
	static game_over_overlay over_overlay;
	
	// timer
	static std::chrono::steady_clock timer;
	
	// game attributes
	GAME_STATE game_state;
	std::chrono::steady_clock::time_point start_time;

	// game elements
	Snake snake;
	std::vector<Wall> outer_walls;
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

	// collecting object locations
	std::vector<std::pair<sf::Vector2f, sf::Vector2f>> object_locations();

	// apple location setter 
	sf::Vector2f get_new_position();

	// timer getter and setters
	std::chrono::steady_clock::duration play_duration(std::chrono::steady_clock::time_point& current_time) {
		return current_time - start_time;
	}

	void reset_timer() {
		start_time = timer.now();
	}

	// loops in each game mode
	void start_screen_loop();
	void game_screen_loop();
	void game_over_screen_loop();

	// main controler of the game loop
	void game_loop();
};
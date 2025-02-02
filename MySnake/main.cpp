#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include <vector>
#include <chrono>

#include "constants.h"
#include "Food.h"
#include "Snake.h"
#include "game_over_overlay.h"
#include "game_play_overlay.h"
#include "game_start_overlay.h"
#include "Game_Manager.h"

using namespace std::literals;

static std::mt19937 rng;
static std::uniform_int_distribution<int> horizontal_placement{ 0, int(constants::window_width / constants::move_distance)-1 };
static std::uniform_int_distribution<int> vertical_placement{ 0, int(constants::window_height / constants::move_distance)-1 };
static std::chrono::steady_clock timer;

int main() {

	Game_Manager game_manager;

	//start the engine
	game_manager.engine();

	return 0;
}
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include <vector>
#include <chrono>

#include "Game_Manager.h"

using namespace std::literals;

int main() {

	Game_Manager game_manager;

	//start the game loop
	game_manager.game_loop();

	return 0;
}
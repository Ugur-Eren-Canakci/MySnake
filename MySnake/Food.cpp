#include "Food.h"
#include <iostream>

sf::Texture Food::texture{"../images/apple_red_32.png"};

Food::Food() : sprite(texture) {
	std::cout << "Food created" << std::endl;
}

Food::Food(int x, int y) : sprite(texture) {
	std::cout << "Food created" << std::endl;
	sprite.setPosition({ x * constants::move_distance, y * constants::move_distance });

};

Food::~Food() {}
#include "Food.h"
#include <iostream>

sf::Texture Food::texture{"C:/Users/ugur_/Desktop/git repos/MySnake/MySnake/images/apple_red_32.png"};

Food::Food() : sprite(texture) {
}

Food::Food(int x, int y) : sprite(texture) {
	sprite.setPosition({ x * constants::move_distance, y * constants::move_distance });

};

Food::~Food() {}
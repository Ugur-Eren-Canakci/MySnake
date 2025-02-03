#include "Food.h"
#include <iostream>

sf::Texture Food::texture{"C:/Users/ugur_/Desktop/git repos/MySnake/MySnake/images/apple_red_32.png"};

Food::Food() : sprite(texture) {
	std::cout << "food positions: (" << get_x() << "," << get_y() << ")" << std::endl;
}


Food::Food(sf::Vector2f location) : sprite(texture) {
	sprite.setPosition(location);
	std::cout << "food positions: (" << get_x() << "," << get_y() << ")" << std::endl;
}

Food::~Food() {}
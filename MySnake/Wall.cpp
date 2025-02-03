#include "Wall.h"

#include <SFML/Graphics.hpp>

sf::Texture Wall::texture("C:/Users/ugur_/Desktop/git repos/MySnake/MySnake/images/wall_block_32_0.png");

Wall::Wall() : sprite{ texture } {}

Wall::Wall(float x, float y) : sprite{ texture } {
	sprite.setPosition({ x,y });
}
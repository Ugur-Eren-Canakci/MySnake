#include "Food.h"

sf::Texture Food::texture{"../images/apple_red_64.png"};

Food::Food() : sprite(texture) {

}

Food::~Food() {}
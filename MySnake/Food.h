#pragma once
#include "Entity.h"


class Food : public Entity {
private:
	static sf::Texture texture;
	sf::Sprite sprite;
public: 
	Food();
	~Food();
};


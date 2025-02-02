#pragma once

#include <SFML/Graphics.hpp>

class overlay {
protected:
	static sf::Font font;

public:
	virtual void show_text(sf::RenderWindow& window) = 0;
};


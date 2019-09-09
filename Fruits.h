#pragma once
#include "SFML/Graphics.hpp"

class Fruits
{

public:

	Fruits();
	//~Fruits();
	void setNewPosition();
	
	void Draw(sf::RenderWindow& window);
	const sf::CircleShape& getFruitShape() const { return fruit; }
	
	const float getRadius() const { return Radius; }

private:

	sf::CircleShape fruit;
	float Radius;
};


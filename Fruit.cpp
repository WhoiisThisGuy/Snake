#include "Fruit.h"

Fruit::Fruit()
	:Radius(10.0f)
{

	fruit.setFillColor(sf::Color::Yellow);
	fruit.setRadius(Radius);
	fruit.setOrigin(Radius,Radius);
	setNewPosition();

}

void Fruit::setNewPosition()
{
	float x,y;


	x = rand() % 930 + 1;
	y = rand() % 740 + 1;
	
	fruit.setPosition(x,y);

}

void Fruit::Draw(sf::RenderWindow& window)
{

	window.draw(fruit);

}
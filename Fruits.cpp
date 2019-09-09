#include "Fruits.h"

Fruits::Fruits()
	:Radius(10.0f)
{

	fruit.setFillColor(sf::Color::Yellow);
	fruit.setRadius(Radius);
	fruit.setOrigin(Radius,Radius);
	setNewPosition();

}

void Fruits::setNewPosition()
{
	float x,y;


	x = rand() % 730 + 1;
	y = rand() % 520 + 1;
	
	fruit.setPosition(x,y);
	

}

void Fruits::Draw(sf::RenderWindow& window)
{

	window.draw(fruit);

}
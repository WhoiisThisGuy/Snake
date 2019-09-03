#include "PytonBody.h"

PytonBody::PytonBody(const sf::Vector2i& tempDir,const sf::Vector2f& prevElemPosition)
	 : Direction(tempDir),
	speed(6.0f)

{
	initBody(tempDir, prevElemPosition);
}

void PytonBody::Update(sf::Vector2i previousElemDirection,sf::Vector2f previousElemPosition)
{

	if (bodyShape.getPosition().x == previousElemPosition.x) {

		Direction = previousElemDirection;

	}
	else if (bodyShape.getPosition().y == previousElemPosition.y) {

		Direction = previousElemDirection;

	}

	bodyShape.move(Direction.x * speed, Direction.y * speed);
	
}

void PytonBody::Draw(sf::RenderWindow& window)
{

	window.draw(bodyShape);
	
}

void PytonBody::initBody(const sf::Vector2i& tempDir, const sf::Vector2f& prevElementPosition)
{
	bodyShape.setFillColor(sf::Color::Green);
	bodyShape.setSize(sf::Vector2f(30.0f, 30.0f));

	if (tempDir.x == 1) {
		bodyShape.setPosition(prevElementPosition.x-30.0f, prevElementPosition.y);
	}
	else if (tempDir.x == -1) {
		bodyShape.setPosition(prevElementPosition.x + 30.0f, prevElementPosition.y);
	}
	else if (tempDir.y == 1) {
		bodyShape.setPosition(prevElementPosition.x, prevElementPosition.y-30.0f);
	}
	else if (tempDir.y == -1) {
		bodyShape.setPosition(prevElementPosition.x, prevElementPosition.y+30.0f);
	}
	else{
		bodyShape.setPosition(prevElementPosition.x + 30.0f, prevElementPosition.y);
		}
	
}

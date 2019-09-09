#include "PytonBody.h"

#define PYTONHEADRADIUS 30.0f

PytonBody::PytonBody(const sf::Vector2i& tempDir,const sf::Vector2f& prevElemPosition)
	 : Direction(tempDir),
	speed(5.0f)

{
	bodyTexture.loadFromFile("Sprite/body.png");
	
	initBody(tempDir, prevElemPosition);
}

PytonBody::PytonBody(const sf::Vector2i& tempDir,const sf::FloatRect& headRect)
	 : Direction(tempDir),
	speed(6.0f)

{
	initBody(tempDir, headRect);
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

//Test with head global bounds

void PytonBody::Update(sf::Vector2i previousElemDirection,sf::FloatRect previousElemPosition)
{

	if (bodyShape.getGlobalBounds().left == previousElemPosition.left) {

		Direction = previousElemDirection;

	}
	else if (bodyShape.getGlobalBounds().top == previousElemPosition.top) {

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
	bodyShape.setTexture(&bodyTexture);
	bodyShape.setSize(sf::Vector2f(30.0f, 30.0f));
	bodyShape.setOrigin(15.0f,15.0f);
	if (tempDir.x == 1) {
		bodyShape.setPosition(prevElementPosition.x-PYTONHEADRADIUS, prevElementPosition.y);
	}
	else if (tempDir.x == -1) {
		bodyShape.setPosition(prevElementPosition.x + PYTONHEADRADIUS, prevElementPosition.y);
	}
	else if (tempDir.y == 1) {
		bodyShape.setPosition(prevElementPosition.x, prevElementPosition.y-PYTONHEADRADIUS);
	}
	else if (tempDir.y == -1) {
		bodyShape.setPosition(prevElementPosition.x, prevElementPosition.y+PYTONHEADRADIUS);
	}
	else{
		bodyShape.setPosition(prevElementPosition.x + PYTONHEADRADIUS, prevElementPosition.y);
		}
	
}

void PytonBody::initBody(const sf::Vector2i& tempDir, const sf::FloatRect& headRect)
{
	//bodyShape.setFillColor(sf::Color::Green);
	bodyShape.setTexture(&bodyTexture);
	bodyShape.setSize(sf::Vector2f(30.0f, 30.0f));
	
	if (tempDir.x == 1) {
		bodyShape.setPosition(headRect.left - 30.0f, headRect.top);
	}
	else if (tempDir.x == -1) {
		bodyShape.setPosition(headRect.left + 30.0f, headRect.top);
	}
	else if (tempDir.y == 1) {
		bodyShape.setPosition(headRect.left, headRect.top - 30.0f);
	}
	else if (tempDir.y == -1) {
		bodyShape.setPosition(headRect.left, headRect.top + 30.0f);
	}
	else{
		bodyShape.setPosition(headRect.left + 30.0f, headRect.top);
		}
	
}
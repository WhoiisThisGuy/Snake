#include "PytonBody.h"

PytonBody::PytonBody(const sf::Vector2i& tempDir,const sf::Vector2f& prevElemPosition)
	 : Direction(tempDir),
	speed(2.0f)

{
	initBody(tempDir, prevElemPosition);
}

void PytonBody::Update(std::shared_ptr<PytonBody>& previousElem)
{

	if (bodyShape.getPosition().x == previousElem->getPosition().x) {

		Direction = previousElem->getDirection();

	}
	else if (bodyShape.getPosition().y == previousElem->getPosition().y) {

		Direction = previousElem->getDirection();

	}

	bodyShape.move(Direction.x * speed * 3, Direction.y * speed * 3);
}

void PytonBody::Update(PytonHead*& head)
{

	if (bodyShape.getPosition().x == head->getPosition().x) {

		Direction = head->getDirection();

	}
	else if (bodyShape.getPosition().y == head->getPosition().y) {

		Direction = head->getDirection();

	}

	bodyShape.move(Direction.x * speed * 3, Direction.y * speed * 3);

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

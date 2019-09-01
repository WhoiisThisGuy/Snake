#include "PytonHead.h"

#define changeLimit 0.1

PytonHead::PytonHead() :

	speed(2.0f),
	Direction(0.0f,0.0f)
{

	InitSnake();

}

void PytonHead::Update()
{

	float moveWithx, moveWithy, nextX, nextY, elapsedTime;
	
	elapsedTime = changedDirTime.getElapsedTime().asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Direction.y != 1 && elapsedTime > changeLimit) {
		changedDirTime.restart().asSeconds();
		Direction.x = 0;
		Direction.y = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && Direction.y != -1 && elapsedTime > changeLimit) {
		changedDirTime.restart().asSeconds();
		Direction.x = 0;
		Direction.y = 1;
	
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Direction.x != 1 && elapsedTime > changeLimit) {
		changedDirTime.restart().asSeconds();
		Direction.x = -1;
		
		Direction.y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Direction.x != -1 && elapsedTime > changeLimit) {
		changedDirTime.restart().asSeconds();
		Direction.x = 1;
		Direction.y = 0;
		
	}

	moveWithx = Direction.x * speed*3;
	moveWithy = Direction.y * speed*3;

	//Oldalak ellenõrzése
	
	nextX = pyton.getPosition().x + moveWithx;

	nextY = pyton.getPosition().y + moveWithy;

	if (nextX > 0 && nextX+29 < 950 && nextY+29 < 750 && nextY > 0) {
		
		pyton.move(sf::Vector2f(moveWithx, moveWithy));
		
	}

}

void PytonHead::Draw(sf::RenderWindow& window) const
{
	
	window.draw(pyton);

}

void PytonHead::InitSnake ()
{
	pyton.setFillColor(sf::Color::Red);
	pyton.setSize(sf::Vector2f(30.0f,30.0f));
	pyton.setPosition(sf::Vector2f(300.0f, 300.0f));
	//pyton.setOrigin(sf::Vector2f(15.0f, 15.0f));
	
}







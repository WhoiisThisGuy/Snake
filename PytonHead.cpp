#include "PytonHead.h"
#include <stdlib.h>
#define changeLimit 0.09


PytonHead::PytonHead() :

	speed(6.0f),
	Direction(0.0f,0.0f),
	isItOver(false)
{

	InitSnake();

}

void PytonHead::Update()
{

	if(CanIchangeDirection())
		Controller();
	
	
	if (DoIleaveTheMap()) {
		
		isItOver = true;
		
	}

}

bool PytonHead::CanIchangeDirection(){ //Find another solution for this maybe.
	
	float elapsedTime;
	bool canChange = true;
	
	
	elapsedTime = changedDirTime.getElapsedTime().asSeconds();
	
	canChange = elapsedTime > changeLimit ? true : false;
	
	return canChange;
}

void PytonHead::Controller(){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Direction.y != 1) {
		
		Direction.x = 0;
		Direction.y = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && Direction.y != -1) {
		
		Direction.x = 0;
		Direction.y = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Direction.x != 1) {
		Direction.x = -1;
		Direction.y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Direction.x != -1) {
		Direction.x = 1;
		Direction.y = 0;
		
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && Direction.x == 0 && Direction.y == 0){
		
		Direction.x = -1;
		Direction.y = 0;
	
	}
	changedDirTime.restart().asSeconds();
}

bool PytonHead::DoIleaveTheMap(){
	
	float moveWithx, moveWithy, nextX, nextY;
	
	moveWithx = Direction.x * speed; 
	moveWithy = Direction.y * speed;

	nextX = pyton.getPosition().x + moveWithx;

	nextY = pyton.getPosition().y + moveWithy;
	
	if (nextX > -1 && nextX+30 < 751 && nextY+30 < 551 && nextY > -1){ //With next step do the head leave the map?
		
		pyton.move(sf::Vector2f(moveWithx, moveWithy));
		
		return false;
	}
		
	return true;
	
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
	
	
}







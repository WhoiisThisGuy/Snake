#include "PytonHead.h"
#include <stdlib.h>

#define CHANGELIMIT 0.09
#define DOWNBORDER 566
#define RIGHTBORDER 766
#define LEFTBORDER 14
#define UPPERBORDER 14


PytonHead::PytonHead() :
	Direction(0.0f,0.0f),
	speed(5.0f),
	isItOver(false)
	
{
	headTexture.loadFromFile("Sprite/head.png");
	InitSnake();

}

void PytonHead::Update()
{
	
	if(CanIchangeDirection()){
		Controller();
	}
	
	if (DoIleaveTheMap()) {
		
		isItOver = true;
		
	}
	//std::cout<<"x: "<<pyton.getPosition().x<<"left: "<<pyton.getPosition().y<<std::endl;
	//system("clear");
}

bool PytonHead::CanIchangeDirection(){ //Find another solution for this maybe.
	
	float elapsedTime;
	bool canChange = true;
	
	
	elapsedTime = changedDirTime.getElapsedTime().asSeconds();
	
	canChange = elapsedTime > CHANGELIMIT ? true : false;
	
	return canChange;
}

void PytonHead::Controller(){
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Direction.y != 1) {
		pyton.setRotation(90.0f);
		Direction.x = 0;
		Direction.y = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && Direction.y != -1) {
		pyton.setRotation(270.0f);
		Direction.x = 0;
		Direction.y = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Direction.x != 1) {
		pyton.setRotation(0.0f);
		Direction.x = -1;
		Direction.y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Direction.x != -1) {
		
		pyton.setRotation(180.0f);
		Direction.x = 1;
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
	
	if (nextX > LEFTBORDER && nextX+30 < RIGHTBORDER && nextY+30 < DOWNBORDER && nextY > UPPERBORDER){ //With next step does the head leave the map?
		
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
	pyton.setTexture(&headTexture);
	pyton.setOrigin(15.0f,15.0f);
	//pyton.setOrigin(20.0f,20.0f);
	//pyton.setRotation(-90.0f);
	//pyton.setFillColor(sf::Color::Red);
	pyton.setSize(sf::Vector2f(30.0f,30.0f));
	pyton.setPosition(sf::Vector2f(300.0f, 300.0f));
	//std::cout<<"top: "<<pyton.getGlobalBounds().top<<"left: "<<pyton.getGlobalBounds().left<<std::endl;
	
}







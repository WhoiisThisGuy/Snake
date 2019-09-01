#pragma once
#include "SFML/Graphics.hpp"
#include "PytonHead.h"
#include <memory>

class PytonBody
	
{

public:

	PytonBody(const sf::Vector2i& tempDir, const sf::Vector2f& prevElemPosition);
	
	void Update(std::shared_ptr<PytonBody> & previousElem);

	void Update(PytonHead*& head);
	
	void Draw(sf::RenderWindow& window);
	const sf::Vector2i getDirection() const { return Direction; }
	const sf::Vector2f getPosition() const { return bodyShape.getPosition(); }
	const sf::Vector2f getChangedDirectionPosition() const { return changedDirectionPosition; }

private: //functions 

	void initBody(const sf::Vector2i& tempDir, const sf::Vector2f& prevElementPosition);

private: // variables

	sf::Vector2f goToPosition;
	sf::Vector2f changedDirectionPosition;
	sf::RectangleShape bodyShape;
	sf::Vector2i Direction;
	float speed;
};


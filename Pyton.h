#pragma once
#include "SFML/Graphics.hpp"
#include "PytonHead.h"
#include "PytonBody.h"
#include "Fruit.h"
#include <list>
#include <memory>

class Pyton
{

public:

	Pyton();

	virtual ~Pyton();

	void Draw(sf::RenderWindow& window);
	void Update(Fruit& fruit);
	void addNewBody();
	bool fruitCollisionCheck(Fruit& fruit);

private:
	
	std::list<std::shared_ptr<PytonBody>> pytonBody;

	PytonHead* head;
};


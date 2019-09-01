#include "Pyton.h"

Pyton::Pyton()
{
	head = new PytonHead();
	addNewBody();
	addNewBody();
}

Pyton::~Pyton()
{
	
	delete head;
	pytonBody.clear(); //szükséges vajon ?

}

void Pyton::Draw(sf::RenderWindow& window)
{
	
	head->Draw(window);

	for (std::list<std::shared_ptr<PytonBody>>::iterator it = pytonBody.begin(); it != pytonBody.end(); ++it) {
	
		(*it)->Draw(window); 

	}
}

void Pyton::Update(Fruit& fruit)
{
	head->Update();

	for (std::list<std::shared_ptr<PytonBody>>::iterator it = pytonBody.begin(), prev; it != pytonBody.end(); prev = it, ++it) {

		if (it != pytonBody.begin()) //furcsa logika
			(*it)->Update(*prev);
		else {
			(*it)->Update(head);
		}
	}

	if (fruitCollisionCheck(fruit)) {
	
		fruit.setNewPosition();
		addNewBody();
	}
		
}

void Pyton::addNewBody()
{
	if (pytonBody.size() != 0) {
		
		std::list<std::shared_ptr<PytonBody>>::iterator it = pytonBody.end();
		--it;
		pytonBody.push_back(std::make_shared<PytonBody>((*it)->getDirection(), (*it)->getPosition()));

	}
	else {
		pytonBody.push_back(std::make_shared<PytonBody>(head->getDirection(), head->getPosition()));
	}

}

bool Pyton::fruitCollisionCheck(Fruit& fruit)
{
		float RectX, RectY, RectWidth, RectHeight, NearestX, NearestY, DeltaX, DeltaY, CircleX, CircleY;

		CircleX = fruit.getFruitShape().getPosition().x;
		CircleY = fruit.getFruitShape().getPosition().y;

		RectX = head->getPytonHeadShape().getGlobalBounds().left;
		RectY = head->getPytonHeadShape().getGlobalBounds().top;

		RectWidth = head->getPytonHeadShape().getGlobalBounds().width;
		RectHeight = head->getPytonHeadShape().getGlobalBounds().height;

		NearestX = std::max(RectX, std::min(CircleX, RectX + RectWidth));
		NearestY = std::max(RectY, std::min(CircleY, RectY + RectHeight));

		DeltaX = CircleX - NearestX;
		DeltaY = CircleY - NearestY;


		if ((DeltaX * DeltaX + DeltaY * DeltaY) < (fruit.getRadius() * fruit.getRadius())) {

			return true;
		}

	return false;


}

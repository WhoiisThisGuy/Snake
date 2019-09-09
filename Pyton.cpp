#include "Pyton.h"

Pyton::Pyton() :
	EndGame(false)
{
	head = new PytonHead();
	addNewBody();
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

void Pyton::Update(Fruits& fruit)
{
	head->Update();
	if(head->isTheGameOver() || CheckBodyCollision())
		EndGame = true;

	//if(!EndGame){ //If I do this it will look dumb when you run into urself. check it if you want to.
		
		if (fruitCollisionCheck(fruit)) {
		
			fruit.setNewPosition();
			addNewBody();
			addNewBody();
			addNewBody();
			addNewBody();
			addNewBody();
			addNewBody();
		}
		
		for (std::list<std::shared_ptr<PytonBody>>::iterator it = pytonBody.begin(), prev; it != pytonBody.end(); prev = it, ++it) {

			if (it != pytonBody.begin()) //furcsa logika, valami olvashatóbbat kitalálni
				(*it)->Update((*prev)->getDirection(),(*prev)->getPosition());
			else {
				(*it)->Update(head->getDirection(),head->getPosition());
				
				}
		}
	//}
}

bool Pyton::CheckBodyCollision(){
	
	int i = 0; //i is for to check only from 4th element (from 3rd 0-1-2-3) [head][0][1][2][3][checkfromhere]
	
	float top,left,height,width;
	
	top = head->getPytonHeadShape().getGlobalBounds().top;
	left = head->getPytonHeadShape().getGlobalBounds().left;
	height = head->getPytonHeadShape().getGlobalBounds().height;
	width = head->getPytonHeadShape().getGlobalBounds().width;
	
	sf::Rect<float> headRect(left,top,width,height);
	
	//only check from the 4th, no way you get into the 2nd , 3rd bodyelement.
		for (std::list<std::shared_ptr<PytonBody>>::iterator it = pytonBody.begin(); it != pytonBody.end(); ++it,++i) {

			if (i>2 && (*it)->getBodyShape().getGlobalBounds().intersects(headRect)){
				
				return true;
			}
		}
		
	return false;
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

bool Pyton::fruitCollisionCheck(Fruits& fruit)
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
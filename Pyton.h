#include "SFML/Graphics.hpp"
#include <list>
#include <memory>
#include "PytonHead.h"
#include "PytonBody.h"
#include "Fruit.h"

class Pyton
{

public:

	Pyton();

	~Pyton();

	void Draw(sf::RenderWindow& window);
	void Update(Fruit& fruit);
	void addNewBody();
	bool fruitCollisionCheck(Fruit& fruit);
	bool ShallIendTheGame(){ return EndGame; }
	bool CheckBodyCollision();
	
private:
	
	std::list<std::shared_ptr<PytonBody>> pytonBody;
	
	PytonHead* head;
	bool EndGame;
};
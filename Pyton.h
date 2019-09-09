#include "SFML/Graphics.hpp"
#include <list>
#include <memory>
#include "PytonHead.h"
#include "PytonBody.h"
#include "Fruits.h"

class Pyton
{

public:

	Pyton();

	~Pyton();

	void Draw(sf::RenderWindow& window);
	void Update(Fruits& fruit);
	void addNewBody();
	bool fruitCollisionCheck(Fruits& fruit);
	bool ShallIendTheGame(){ return EndGame; }
	bool CheckBodyCollision();
	
private:
	
	std::list<std::shared_ptr<PytonBody>> pytonBody;
	
	PytonHead* head;
	bool EndGame;
};
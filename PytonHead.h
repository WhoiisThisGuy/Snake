#include "SFML/Graphics.hpp"


class PytonHead
{
public:

	PytonHead();
	void Update();
	void Draw(sf::RenderWindow& window) const;

	const sf::Vector2i& getDirection() const { return Direction; }
	const sf::Vector2f& getPosition() const { return pyton.getPosition(); }

	const sf::Vector2f& getChangedDirectionPosition() const { return ChangedDirectionPosition; }

	const sf::RectangleShape& getPytonHeadShape() const { return pyton; }

	const sf::Vector2i& getprevDirection() const { return prevDirection; }

	const bool isTheGameOver() const { return isItOver; }

private:

	bool fruitCollisionCheck();
	void InitSnake();
	bool DoIleaveTheMap();
	void Controller();
	bool CanIchangeDirection();
	
private:
	

	
	sf::Clock changedDirTime;
	sf::Vector2i prevDirection;
	sf::Vector2f ChangedDirectionPosition;
	sf::RectangleShape pyton;
	sf::Vector2i Direction;
	float speed;
	bool isItOver;
};

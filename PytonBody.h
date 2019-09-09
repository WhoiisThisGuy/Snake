#include "SFML/Graphics.hpp"

class PytonBody
	
{

public:

	PytonBody(const sf::Vector2i& tempDir, const sf::Vector2f& prevElemPosition);
	PytonBody(const sf::Vector2i& tempDir,const sf::FloatRect& headRect);
	
	void Update(sf::Vector2i previousElemDirection,sf::Vector2f previousElemPosition);
	void Update(sf::Vector2i previousElemDirection,sf::FloatRect previousElemPosition);
	
	void Draw(sf::RenderWindow& window);
	const sf::Vector2i getDirection() const { return Direction; }
	const sf::Vector2f getPosition() const { return bodyShape.getPosition(); }
	const sf::Vector2f getChangedDirectionPosition() const { return changedDirectionPosition; }
	const sf::RectangleShape getBodyShape() const { return bodyShape; }

private: //functions 

	void initBody(const sf::Vector2i& tempDir, const sf::Vector2f& prevElementPosition);
	void initBody(const sf::Vector2i& tempDir, const sf::FloatRect& headRect);
private: // variables

	sf::Texture bodyTexture;
	sf::Vector2f goToPosition;
	sf::Vector2f changedDirectionPosition;
	sf::RectangleShape bodyShape;
	sf::Vector2i Direction;
	float speed;
};

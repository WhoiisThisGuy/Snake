#include <SFML/Graphics.hpp>
#include <iostream>
#include <exception>
#include "Pyton.h"
#include "Fruits.h"
#include "Gate.h"

class Game {

public:

	Game();
	
	~Game();

	void run();
	void Update();
	void UpdateDt();
	void UpdateSfmlEvents();
	void Render();

private:

	void Restart();

private:

	std::shared_ptr<Pyton> py;
	bool GameOver;
	sf::RenderWindow window;
	sf::Event event;
	Fruits fruit;
	Gate testGate;
};

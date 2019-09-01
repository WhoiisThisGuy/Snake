#pragma once
#include <SFML/Graphics.hpp>
#include "Pyton.h"
#include <iostream>
#include <exception>


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

	Pyton* py;
	

	sf::RenderWindow window;
	sf::Event event;

	Fruit fruit;
};

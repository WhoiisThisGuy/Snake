#include "Game.h"
#include <fstream>

Game::Game()
try : window(sf::VideoMode(950.0f, 750.0f), "Snake"), py(new Pyton()){
	
	window.setFramerateLimit(60);
}
catch (std::exception e) {

	std::cout << e.what() << std::endl;

}

Game::~Game()
{

	delete py;
	
}

void Game::run()
{
	
	while (window.isOpen())
	{
		
		Update();
		Render();
	}

}

void Game::Update()
{
	UpdateSfmlEvents();
	py->Update(fruit);
}

void Game::UpdateSfmlEvents()
{
	
	while (window.pollEvent(event))
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
		if (event.type == sf::Event::Closed)
			window.close();

	}

}

void Game::Render()
{
		
		window.clear();
		py->Draw(window);
		fruit.Draw(window);
		window.display();
	
}



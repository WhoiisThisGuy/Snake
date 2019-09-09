#include "Game.h"
#include <fstream>

Game::Game()
try 
: window(sf::VideoMode(750.0f, 550.0f), "Snake"),

GameOver(false)

{

	py = std::make_shared<Pyton>();
	window.setFramerateLimit(70);
}
catch (std::exception e) {

	std::cout << e.what() << std::endl;

}

Game::~Game()
{
	
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
	//Check for game over
	UpdateSfmlEvents();
	if(!(py->ShallIendTheGame())){
		py->Update(fruit);
	}

}

void Game::UpdateSfmlEvents()
{
	
	while (window.pollEvent(event))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			Restart();
	}

}

void Game::Render()
{
		
		window.clear();
		testGate.Draw(window);
		py->Draw(window);
		fruit.Draw(window);
		
		window.display();
	
}

void Game::Restart(){

		py.reset(new Pyton());
		GameOver = false;
	}


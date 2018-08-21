#include "stdafx.h"

bool Game::isAPressed(0),
	Game::isDPressed(0);

Player player({ 50, 200 });

Game::Game()
{
	std::cout << "Size and title not specified!" << std::endl;
}

Game::Game(const int & windowWidth, const int & windowHeight, const sf::String & windowTitle)
	: window(sf::VideoMode(windowWidth, windowHeight), windowTitle)
{
	
}

Game::~Game()
{
	std::cout << "You just deleted the window!" << std::endl;
}

void Game::run()
{
	player.setPosition({ 0, this->window.getSize().y - player.getSize().y / 2 });

	sf::Clock gameClock;
	float deltaTime = 1 / 60.f;
	this->window.setFramerateLimit(30);

	while (this->window.isOpen())
	{
		float frameStart = gameClock.getElapsedTime().asSeconds();

		events();
		updateAll(deltaTime, this->window);
		this->window.clear();
		drawAll(this->window);
		this->window.display();
		deltaTime = (gameClock.getElapsedTime().asSeconds() - frameStart) * 10;
	}
}

void Game::events()
{
	sf::Event event;

	while (this->window.pollEvent(event))
	{

		if (event.type == sf::Event::Closed)
		{
			this->window.close();
			std::cout << "You just closed the window!" << std::endl;
		}

		if (event.type == sf::Event::Resized)
		{
			std::cout << "New width is " << this->window.getSize().x << ", new height is " << this->window.getSize().y << std::endl;
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::A) {
				isAPressed = true;
			}
				
			if (event.key.code == sf::Keyboard::D)
			{
				isDPressed = true;
			}
				
		}

		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::A)
				isAPressed = false;
			if (event.key.code == sf::Keyboard::D)
				isDPressed = false;
		}
	}

}

void Game::updateAll(const float & deltaTime, sf::RenderWindow& window)
{
	player.update(deltaTime, window);
}


void Game::drawAll(sf::RenderWindow& window)
{
	player.draw(this->window);
}

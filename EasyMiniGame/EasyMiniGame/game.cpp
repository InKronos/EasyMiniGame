#include "stdafx.h"

Game::Game()
{
	std::cout << "Size and title not specified!" << std::endl;
}

Game::Game(const int & windowWidth, const int & windowHeight, const sf::String & windowTitle)
	: window(sf::VideoMode(windowWidth, windowHeight), windowTitle)
{
	window.setFramerateLimit(30);
}

Game::~Game()
{
	std::cout << "You just deleted the window!" << std::endl;
}

void Game::run()
{
	while (this->window.isOpen())
	{
		events();
		update();
		draw();
	}
}

void Game::events()
{
	sf::Event evnt;

	while (this->window.pollEvent(evnt))
	{
		if (evnt.type == sf::Event::Closed)
		{
			this->window.close();
			std::cout << "You just closed the window!" << std::endl;
		}
		if (evnt.type == sf::Event::Resized)
		{
			std::cout << "New width is " << this->window.getSize().x << ", new height is " << this->window.getSize().y << std::endl;
		}
	}

}

void Game::update()
{
}


void Game::draw()
{
	this->window.clear();

	this->window.display();

}

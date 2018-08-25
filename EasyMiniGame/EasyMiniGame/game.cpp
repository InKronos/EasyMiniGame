#include "stdafx.h"

bool Game::isAPressed(0),
	Game::isDPressed(0),
	Game::isSpacePressed(0);

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

		if (!player.isDead) {
			spawner(this->window);
			updateAll(deltaTime, this->window);
			this->window.clear();
			drawAll(this->window);
			this->window.display();
		}
		else {
			sf::Text deadText;
			deadText.setString("You are dead, Press space to Continue");
			deadText.setCharacterSize(32);
			deadText.setFillColor(sf::Color::White);
			deadText.setStyle(sf::Text::Bold);
			//deadText.setPosition({ this->window.getSize().x / 2, this->window.getSize().y / 2 });
			this->window.draw(deadText);
			//this->window.display();
	
			if (Game::isSpacePressed == true) {
				player.setPosition({ 0, this->window.getSize().y - player.getSize().y / 2 });
				for (auto i = 0u; i < List::allFallingObject.size(); i++)
				{
					List::allFallingObject.erase(i + List::allFallingObject.begin());
					i--;
				}
				player.isDead = false;
				Game::isSpacePressed = false;
			}
		}
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

			if (event.key.code == sf::Keyboard::Space)
			{
				isSpacePressed = true;
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

void Game::spawner(sf::RenderWindow& window)
{
	srand(time(NULL));
	float point;
	float lastPosition = 0;
	if (List::allFallingObject.size() < 2){
		for (int i = 0; i < rand() % 50; i++) {
			point = rand() % window.getSize().x + 1;
			std::cout << point << std::endl;
			if (lastPosition == point) {
				point = rand() % 50 + 1;
				std::cout << point << std::endl;
				FallingObject object({ point, -50 });
				List::allFallingObject.push_back(object);
			}
			else 
			{
				FallingObject object({ point, -50 });
				List::allFallingObject.push_back(object);
			}
	
			lastPosition = point;
		}
	}
}

void Game::updateAll(const float & deltaTime, sf::RenderWindow& window)
{
	player.update(deltaTime, window);
	for (auto i = 0u; i < List::allFallingObject.size(); i++)
	{
		List::allFallingObject[i].update(deltaTime, window);
		if (List::allFallingObject[i].isDead)
		{
			List::allFallingObject.erase(i + List::allFallingObject.begin());
			i--;
		}
	}
}

void Game::drawAll(sf::RenderWindow& window)
{
	player.draw(this->window);
	for (auto i = 0u; i < List::allFallingObject.size(); i++)
	{
		List::allFallingObject[i].draw(window);
	}
}

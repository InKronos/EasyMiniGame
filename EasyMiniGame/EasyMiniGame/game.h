#pragma once

#include "stdafx.h"

class Game
{
private:
	sf::RenderWindow window;
public:
	Game();
	Game(const int & windowWidth = 500, const int & windowHeight = 500, const sf::String & windowName = "SFML GAME!");
	~Game();
	void run();
	static bool isAPressed,
		isDPressed;

private:
	void events();
	void updateAll(const float & deltaTime, sf::RenderWindow& window);
	void drawAll(sf::RenderWindow& window);

};

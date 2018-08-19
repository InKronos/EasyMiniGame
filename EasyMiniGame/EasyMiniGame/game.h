#pragma once

#include "stdafx.h"

class Game
{
private:
	sf::RenderWindow window;
public:
	Game();
	Game(const int & windowWidth = 1024, const int & windowHeight = 768, const sf::String & windowName = "SFML GAME!");
	~Game();
	void run();

private:
	void events();
	void update();
	void draw();

};

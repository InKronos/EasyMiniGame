#pragma once

#include "stdafx.h"

class Game
{
private:
	sf::RenderWindow window;
public:
	Game();
	Game(const int & windowWidth, const int & windowHeight, const sf::String & windowName);
	~Game();
	void run();

private:
	void events();
	void update();
	void draw();

};

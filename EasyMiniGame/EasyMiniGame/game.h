#pragma once

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


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

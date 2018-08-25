#pragma once

#include "stdafx.h"

class Player 
	: public SceneObject
{
private:
	float playerSpeed;
	sf::Vector2f playerSize;

public:
	Player();
	Player(const sf::Vector2f& position = { 0, 20 }, const sf::Vector2f& size = {50, 50});
	~Player();
	void update(const float & deltaTime, sf::RenderWindow& window) override;
	const sf::Vector2f & getSize();

private:
	void playerMove(const float & deltaTime);
	void WindowCheckCollision(sf::RenderWindow& window);
	void ObjectCollision();
};
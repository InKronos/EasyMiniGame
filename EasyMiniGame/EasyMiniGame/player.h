#pragma once

#include "stdafx.h"

class Player 
	: public SceneObject
{
private:
	float playerSpeed;

public:
	Player();
	Player(const sf::Vector2f& position = { 0, 20 }, const sf::Vector2f& size = {100, 100});
	~Player();
	void update(const float& deltaTime) override;

private:
	void playerCheckCollision(sf::RenderWindow& window);
};
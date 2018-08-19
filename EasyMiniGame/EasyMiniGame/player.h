#pragma once

#include "stdafx.h"

class Player : public SceneObject
{
private:
	float playerSpeed;

public:
	Player();
	Player(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 10, 10 }, const float & playerSpeed = 1.0f);
	~Player();
	void update(const float& deltaTime) override;

private:
	void playerKeyboard();
	void playerCheckCollision(sf::RenderWindow& window);
};
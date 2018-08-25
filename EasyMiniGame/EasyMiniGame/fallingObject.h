#pragma once

#include "stdafx.h"

class FallingObject
	: public SceneObject
{
private:
	float velY;
	void fall(const float & deltaTime);
	void destroy(sf::RenderWindow& window);

public:
	FallingObject(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 20, 20 });
	~FallingObject();

	void update(const float & deltaTime, sf::RenderWindow& window) override;
};

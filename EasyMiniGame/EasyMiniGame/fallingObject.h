#pragma once

#include "stdafx.h"

class FallingObject
	: public SceneObject
{
private:
	float velY;
public:
	FallingObject(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 50, 50 });
	~FallingObject();

	void update(const float & deltaTime) override;
};

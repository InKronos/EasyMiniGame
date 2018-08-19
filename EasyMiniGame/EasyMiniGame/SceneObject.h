#pragma once

#include "stdafx.h"

class SceneObject
{
protected:
	sf::RectangleShape shape;
	sf::Vector2f position;
public:
	SceneObject(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 10, 10 });
	~SceneObject() {};

	sf::Vector2f getPosition() const;
	void setPosition(const sf::Vector2f& position);

	virtual void update(const float& deltaTime) = 0;
	void draw(sf::RenderWindow& window) const;
};
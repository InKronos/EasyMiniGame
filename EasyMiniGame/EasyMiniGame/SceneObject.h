#pragma once

#include "stdafx.h"

class SceneObject
{
protected:
	sf::RectangleShape shape;
	sf::Vector2f position;
public:
	SceneObject(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 20, 20 });
	~SceneObject() {};

	sf::Vector2f getPosition() const;
	void setPosition(const sf::Vector2f& position);

	virtual void update(const float & deltaTime, sf::RenderWindow& window) = 0;
	void draw(sf::RenderWindow& window) const;
};
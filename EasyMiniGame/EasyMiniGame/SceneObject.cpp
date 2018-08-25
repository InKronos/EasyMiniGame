#include "stdafx.h"

SceneObject::SceneObject(const sf::Vector2f & position, const sf::Vector2f & size)
	: position(position), isDead(0)
{
	this->shape.setPosition(this->position);
	this->shape.setSize(size);
	this->shape.setOrigin(size / 2.f);
}

sf::Vector2f SceneObject::getPosition() const
{
	return this->position;
}

void SceneObject::setPosition(const sf::Vector2f & position)
{
	this->position = position;
}

void SceneObject::draw(sf::RenderWindow & window) const
{
	window.draw(this->shape);
}

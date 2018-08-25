#include "stdafx.h"

FallingObject::FallingObject(const sf::Vector2f & position, const sf::Vector2f & size)
	: SceneObject(position, size)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 255);
	int r = distribution(generator);
	int g = distribution(generator);
	int b = distribution(generator);

	this->shape.setFillColor({ 255, 0, 255 });
}

FallingObject::~FallingObject()
{
	std::cout << "Object is outside window";
}

void FallingObject::update(const float & deltaTime)
{
	this->velY += deltaTime * 1.2;
	this->position.y += this->velY * deltaTime;

	this->shape.setPosition(this->position);
}

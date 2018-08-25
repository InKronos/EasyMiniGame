#include "stdafx.h"

FallingObject::FallingObject(const sf::Vector2f & position, const sf::Vector2f & size)
	: SceneObject(position, size)
{
	srand(time(NULL));

	this->isDead = false;
	this->shape.setFillColor(sf::Color( rand() % 255 + 100, rand() % 255 + 100, rand() % 255 + 100));
}

FallingObject::~FallingObject()
{
	std::cout << "Object is outside window" <<std::endl;
}

void FallingObject::update(const float & deltaTime, sf::RenderWindow& window)
{
	this->fall(deltaTime);
	this->destroy(window);
}

void FallingObject::fall(const float & deltaTime)
{
	srand(time(NULL));
	this->velY += deltaTime * ((rand() % 1000) / 130) ;
	this->position.y += this->velY * deltaTime;

	this->shape.setPosition(this->position);
}

void FallingObject::destroy(sf::RenderWindow & window)
{
	if (this->position.y > (window.getSize().y + (this->shape.getSize().y / 2))) 
		isDead = true;
}


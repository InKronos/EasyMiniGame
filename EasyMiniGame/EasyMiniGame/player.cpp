#include "stdafx.h"

Player::Player()
{

}

Player::Player(const sf::Vector2f & position, const sf::Vector2f& size)
	: SceneObject(position, size)
{
	this->shape.setFillColor({ 255, 0, 0 });
}

Player::~Player()
{
	std::cout << "Player just got deleted!" << std::endl;
}

void Player::update(const float & deltaTime)
{
	if (Game::isAPressed) 
		this->position.x -= 50 * deltaTime;
	if (Game::isDPressed)
		this->position.x += 50 * deltaTime;

	this->shape.setPosition(this->position);
}

void Player::playerCheckCollision(sf::RenderWindow& window)
{
	/*
	if (this->position.x < 0)
	{
		this->position.x = 0;
		this->shape.setPosition(this->position);
	}
	*/
}

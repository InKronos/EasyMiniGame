#include "stdafx.h"

Player::Player()
{

}

Player::Player(const sf::Vector2f & position, const sf::Vector2f& size)
	: SceneObject(position, size)
{
	this->shape.setFillColor({ 255, 0, 0 });
	this->playerSize = this->shape.getSize();
}

Player::~Player()
{
	std::cout << "Player just got deleted!" << std::endl;
}

void Player::update(const float & deltaTime, sf::RenderWindow& window)
{
	this->playerMove(deltaTime);
	this->WindowCheckCollision(window);
	this->ObjectCollision();
}

const sf::Vector2f & Player::getSize()
{
	return this->playerSize;
}

void Player::playerMove(const float & deltaTime)
{
	if (Game::isAPressed)
		this->position.x -= 100 * deltaTime;
	if (Game::isDPressed)
		this->position.x += 100 * deltaTime;

	this->shape.setPosition(this->position);
}

void Player::WindowCheckCollision(sf::RenderWindow& window)
{
	if (this->position.x < this->shape.getSize().x/2)
	{
		this->position.x = this->shape.getSize().x/2;
		this->shape.setPosition(this->position);
	}
	if (this->position.x > window.getSize().x - this->shape.getSize().x / 2)
	{
		this->position.x = window.getSize().x - this->shape.getSize().x / 2;
		this->shape.setPosition(this->position);
	}
}

void Player::ObjectCollision()
{
	for (auto i = 0u; i < List::allFallingObject.size(); i++)
	{
		float dX = this->position.x - List::allFallingObject[i].getPosition().x;
		float dY = this->position.y - List::allFallingObject[i].getPosition().y;

		float length = sqrt(dX * dX + dY * dY);

		if (length < 0 + this->shape.getSize().x) {
			isDead = true;
			std::cout << length << std::endl;
		}
	}
}

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
	this->playerMove(deltaTime, window);
	this->playerCheckCollision(window);
}

const sf::Vector2f & Player::getSize()
{
	return this->playerSize;
}

void Player::playerMove(const float & deltaTime, sf::RenderWindow & window)
{
	if (Game::isAPressed)
		this->position.x -= 50 * deltaTime;
	if (Game::isDPressed)
		this->position.x += 50 * deltaTime;

	this->shape.setPosition(this->position);
}

void Player::playerCheckCollision(sf::RenderWindow& window)
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

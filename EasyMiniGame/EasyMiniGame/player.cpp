#include "player.h"

Player::Player()
{

}

Player::Player(const sf::Vector2f & position, const sf::Vector2f & size, const float & playerSpeed)
{
	this->shape.setPosition(position);
	this->shape.setSize(size);
	this->shape.setFillColor(sf::Color::Magenta);
	this->playerSpeed = playerSpeed;
}

void Player::update(const float & deltaTime)
{
	playerKeyboard();
}

Player::~Player()
{
	std::cout << "Player just got deleted!" << std::endl;
}

void Player::playerKeyboard()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->position.x -= playerSpeed;
		this->shape.setPosition(this->position);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->position.x += playerSpeed;
		this->shape.setPosition(this->position);
	}
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

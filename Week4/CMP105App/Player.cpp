#include "Player.h"
#include <iostream>

Player::Player()
{
	std::cout << "Player has been created" << std::endl;
	
	

	speed = 200.f;
	
}

Player::~Player()
{
	std::cout << "Player has been destroyed" << std::endl;
}

void Player::handleInput(float dt, sf::Vector2u winParam)
{
		
	playerPos = getPosition();
	playerSize = getSize();

	if (input->isKeyDown(sf::Keyboard::Up))
	{
		if (playerPos.y > 0)
		{
			move(0, -speed * dt);
		}
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		if(playerPos.y + playerSize.y < winParam.y)
		{
		move(0, speed * dt);
		}
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		if(playerPos.x > 0)
		{
		move(-speed * dt, 0);
		}	
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		if(playerPos.x + playerSize.x < winParam.x)
		{
			move(speed * dt, 0);
		}
	}

}



#include "enemy.h"

Enemy::Enemy()
{
	speed = 0.f;
	dirX = 1;
	dirY = 1;
	window = NULL;
}

Enemy::Enemy(sf::RenderWindow* wndw)
{
	window = wndw;
	dirX = 1;
	dirY = 1;


}

Enemy::~Enemy()
{

}

void Enemy::movement(float dt)
{
	windowSize = window->getSize();
	enemyPos = getPosition();
	enemySize = getSize();


	if (enemyPos.x + enemySize.x >= windowSize.x || enemyPos.x <= 0 )
	{
		dirX *= -1;
	}
	if (enemyPos.y + enemySize.y >= windowSize.y || enemyPos.y <= 0)
	{
		dirY *= -1;
	}

	move((dirX * speed * dt), (dirY * speed * dt));
}


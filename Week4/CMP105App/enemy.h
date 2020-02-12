#pragma once
#include "Framework/GameObject.h"

class Enemy :
	public GameObject
{
	public:
		Enemy();
		Enemy(sf::RenderWindow* wndw);
		~Enemy();

		void movement(float dt);
	
		

		sf::Vector2u windowSize;
		sf::Vector2f enemyPos;
		sf::Vector2f enemySize;

		float speed;


		sf::Texture texture;

		int dirX;
		int dirY;

private:
	sf::RenderWindow* window;

};


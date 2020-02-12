#pragma once
#include "Framework/GameObject.h"


class Player :
	public GameObject
{
	private:
		
	public:
		Player();
		~Player();

		void handleInput(float dt,sf::Vector2u winParam);
		
		sf::Texture playerTexture;
		sf::Vector2f playerPos;
		sf::Vector2f playerSize;

		float speed;


};


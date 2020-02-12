#pragma once
#include "Framework/GameObject.h"


class Cursor :
	public GameObject
{
	public:
		Cursor();
		Cursor(sf::RenderWindow* wndw);
		~Cursor();

	

		void updateCursor(int,int);

		sf::Texture texture;

private:
	sf::RenderWindow* window;
};


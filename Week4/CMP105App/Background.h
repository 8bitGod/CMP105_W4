#pragma once
#include "Framework/GameObject.h"
class Background :
	public GameObject
{
	public:

		Background();
		Background(sf::RenderWindow* wndw);
		~Background();

	
		

		
		sf::Texture background;	

	private:

		sf::RenderWindow* window;

		
		
		

};


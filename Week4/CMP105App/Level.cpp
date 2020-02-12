#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	
	
	user.setInput(input);
	user.playerTexture.loadFromFile("gfx/Mushroom.png");
	user.setTexture(&user.playerTexture);
	user.setSize(sf::Vector2f(100, 100));
	user.setPosition(100, 100);
	

	enemy1 = Enemy(window);
	enemy1.texture.loadFromFile("gfx/goomba.png");
	enemy1.setTexture(&enemy1.texture);
	enemy1.setSize(sf::Vector2f(50, 50));
	enemy1.setPosition(250, 250);
	enemy1.speed = 120.f;

	enemy2 = Enemy(window);
	enemy2.texture.loadFromFile("gfx/Beach_Ball.png");
	enemy2.setTexture(&enemy2.texture);
	enemy2.setSize(sf::Vector2f(50, 50));
	enemy2.setPosition(700, 469);
	enemy2.speed = 220.f;
	enemy2.dirY *= -1;
	enemy2.dirX *= -1;

	pointer = Cursor(window);

	pointer.texture.loadFromFile("gfx/mouse.png");
	pointer.setSize(sf::Vector2f(30,30));
	pointer.setTexture(&pointer.texture);

	design = Background(window);
	design.setInput(input);
	design.background.loadFromFile("gfx/Level1_1.png");
	design.setTexture(&design.background);
	design.setSize(sf::Vector2f(11038, 675));
	design.setPosition(0, 0);
	
	camera.setSize(600,600);
	window->setView(camera);
}


Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	sf::Vector2u winSize = window->getSize();

	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	

	user.handleInput(dt,winSize);


	if (input->isKeyDown(sf::Keyboard::D))
	{
		camera.move(200*dt, 0);
		window->setView(camera);

		
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		
		camera.move(-200*dt, 0);
		window->setView(camera);
	}
}

// Update game objects
void Level::update(float dt)
{
	enemy1.movement(dt);
	enemy2.movement(dt);
	
	mouseX = input->getMouseX();
	mouseY = input->getMouseY();

	pointer.updateCursor(mouseX,mouseY);

}

// Render level
void Level::render()
{
	beginDraw();
	
	window->draw(design);
	window->draw(enemy2);
	window->draw(enemy1);
	window->draw(user);
	window->draw(pointer);
	
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}
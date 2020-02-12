#include "Cursor.h"


Cursor::Cursor()
{
	setInput(input);

}

Cursor::Cursor(sf::RenderWindow* wndw)
{

	window = wndw;

	window->setMouseCursorVisible(false);
}

Cursor::~Cursor()
{

}

void Cursor::updateCursor(int xPos, int yPos)
{

	setPosition(xPos, yPos);
}
#include "Block.h"

Block::Block(float blockHeight, float blockWidth, float posX, float posY, int blockHealth, sf::Color blockColor)
{
	height = blockHeight;
	width = blockWidth;
	x = posX;
	y = posY;
	health = blockHealth;
	color = blockColor;
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(width, height));
	shape.setFillColor(color);
	shape.setPosition(x, y);
	shape.setOutlineThickness((height + width) / -40);
	shape.setOutlineColor(sf::Color::Black);
	
}



void Block::updateHealth(int new_health)
{
	health += new_health;
}

float Block::getHeight()
{
	return height;
}

float Block::getWidth()
{
	return width;
}

float Block::getPosX()
{
	return x;
}

float Block::getPosY()
{
	return y;
}

sf::Color Block::getColor()
{
	return color;
}




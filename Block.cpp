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


bool Block:: processBlock(Block& block) {
	int health = block.getHealth(); // получаем здоровье блока
	if (health < 0) {
		return false;
	}
	if (health > 1) {
		block.setHealth(health - 1);
		block.setFillColor(getColorForHealth(health - 1));
		return false;
	}
	return true;
}
sf::Color Block::getColorForHealth(int health) {
	switch (health) {
	case 1:
		return sf::Color::RED;
	case 2:
		return sf::Color::YELLOW;
	case 3:
		return sf::Color::BlUE;
	default:
		return sf::Color::Green;
	}
}
void Block::setHealth(int new_health)
{
	health = new_health;
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

int Block::getHealth()
{
	return health;
}

sf::Color Block::getColor()
{
	return color;
}




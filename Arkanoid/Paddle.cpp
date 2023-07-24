#include "Paddle.h"


Paddle::Paddle()
{
	width =600/4;
	height = 10;
	shape.setSize(sf::Vector2f(width, height));
	x = 600/4+width/2;
	y = 900-100;
	shape.setFillColor(sf::Color::Magenta);
	shape.setPosition(x, y);
	
}

float Paddle::GetHeight(void)
{
	return height;
}

float Paddle::GetWidth(void)
{
	return width;
}

float Paddle::GetPosX(void)
{
	return x;
}

float Paddle::GetPosY(void)
{
	return y;
}

void Paddle::Move(float userWindowWidth)
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
		if (x >= 0)
			x -= BAR_SPEED;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
		if (x <= userWindowWidth - width)
			x += BAR_SPEED;
}

void Paddle::Draw(std::shared_ptr<sf::RenderWindow> window)
{
	shape.setSize(sf::Vector2f(width, height));

	shape.setFillColor(sf::Color::Magenta);
	shape.setPosition(x, y);

	
}

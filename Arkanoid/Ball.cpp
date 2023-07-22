#include "../../Arcanoid_try2/Arcanoid_try2/Ball.h"

Ball::Ball()
{
	shape.setRadius(15);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(285, 765);
}

void Ball::move()
{
	shape.move(0.52, -0.52);
}



float Ball::getRadius()
{
	return radius;
}

float Ball::getX()
{
	return x;
}

float Ball::getY()
{
	return y;
}

float Ball::getSpeedX()
{
	return speedX;
}

float Ball::getSpeedY()
{
	return speedY;
}

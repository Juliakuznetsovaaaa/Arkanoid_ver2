#include "Bonus.h"

void BallSpeed::active(sf::Vector2f& velocity)
{
	velocity*=speedMultiplier;
}

Bonus::Bonus(float posX, float posY)
{
	bonusBall.setFillColor(sf::Color::White);
	bonusBall.setRadius(10);
	bonusBall.setPosition(posX, posY);
	
}

void PaddelWidth::active(sf::Vector2f& velocity)
{
	velocity.x += 100;
}

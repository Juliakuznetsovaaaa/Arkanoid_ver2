#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Ball {
protected:
	float radius;
	float speedX, speedY;
	float x, y;
	
public:
	sf::CircleShape shape;
	Ball();
	~Ball() {};
	void move();
	float getRadius();
	float getX();
	float getY();
	float getSpeedX();
	float getSpeedY();
};
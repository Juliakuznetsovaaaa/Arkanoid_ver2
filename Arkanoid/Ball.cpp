#pragma once
#include "../../Arcanoid_try2/Arcanoid_try2/Ball.h"
#include<algorithm>
#include <iostream>



Ball::Ball()
{
	shape.setRadius(15);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(285, 765);
	speedX = 0;
}

void Ball::zeroSpeed( Paddle& paddle,  int windowWidth)
{
	double spinBall = 2.52;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		if (paddle.shape.getPosition().x < windowWidth - paddle.GetWidth()) {
			paddle.shape.move(spinBall, 0);
			if (!isStart)
				shape.move(spinBall, 0);
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		if (paddle.shape.getPosition().x > 0) {
			paddle.shape.move(-spinBall, 0);
			if (!isStart)
				shape.move(-spinBall, 0);
		}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		speedX = spinBall;
		speedY = -spinBall;
		isStart = true;

	}
	

}

void Ball::move( Paddle& paddle, std::vector<sf::RectangleShape>& blocks, sf::RenderWindow& window)
{
	colossionWithBlock(blocks, window);
	double spinBall = 2.5;
	if (isStart) {
		
		shape.move(speedX, speedY);
		
		if (shape.getPosition().x + shape.getRadius() >= 600 || shape.getPosition().x + shape.getRadius() <= 0) {
			speedX = -speedX;
			shape.move(speedX, speedY);
			
		}
			
		
		if (shape.getPosition().y + shape.getRadius() <= 0) {
			speedY = -speedY;
			shape.move(speedX, speedY);
			
		}
		if (shape.getPosition().x >= paddle.shape.getPosition().x-shape.getRadius() && shape.getPosition().x <= paddle.shape.getPosition().x+ paddle.shape.getSize().x+shape.getRadius() && shape.getPosition().y > paddle.shape.getPosition().y - paddle.shape.getSize().y - shape.getRadius() && shape.getPosition().y < paddle.shape.getPosition().y) {
			speedY = -speedY;
			shape.move(speedX, speedY);
			
		}
		if (shape.getPosition().y > paddle.shape.getPosition().y) {
			isStart = false;
			paddle.shape.setPosition(paddle.GetPosX(), paddle.GetPosY());
			shape.setPosition(285, 765);
		}
	}
}

void Ball::colossionWithBlock(std::vector<sf::RectangleShape>& blocks, sf::RenderWindow& window )
{
	std::vector<sf::RectangleShape> remainingBlocks;
	
	for(unsigned k = 0; k < blocks.size(); k++) {
		if (shape.getGlobalBounds().intersects(blocks[k].getGlobalBounds())) {
			speedY = -speedY;
			shape.move(speedX, speedY);
		}
		else {
			remainingBlocks.push_back(blocks[k]);
		}
	}

	blocks = remainingBlocks;


	
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

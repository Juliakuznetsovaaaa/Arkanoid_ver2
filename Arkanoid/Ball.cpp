#pragma once
#include "../../Arcanoid_try2/Arcanoid_try2/Ball.h"
#include<algorithm>
#include <iostream>



Ball::Ball()
{
	shape.setRadius(11);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(285, 765);
	speedX = 0;
}

void Ball::zeroSpeed(Paddle& paddle, int windowWidth)
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
		speedX = 1;
		speedY = -1;
		isStart = true;

	}


}

void Ball::move(Paddle& paddle, std::vector<sf::RectangleShape>& blocks, sf::RenderWindow& window)
{
	//colossionWithBlock(blocks, window);
	double spinBall = 2.5;
	if (isStart) {

		shape.move(speedX*spinBall, speedY*spinBall);

		if (shape.getPosition().x + shape.getRadius() >= 600 || shape.getPosition().x + shape.getRadius() <= 0) {
			double angle = atan2(speedY, speedX);
			std::cout << "angel " << angle << std::endl;// вычисляем угол направления в радианах
			double newAngle = angle + tan(angle); // вычисляем новый угол, увеличивая его на тангенс текущего угла
			double newSpeedX = cos(newAngle); // вычисляем новые значения скорости по осям X и Y
			double newSpeedY = sin(newAngle);
			shape.move(newSpeedX * spinBall, newSpeedY * spinBall); // перемещаем шарик


		}


		if (shape.getPosition().y + shape.getRadius() <= 0) {
			/*speedY *= -1;
			shape.move(speedX * spinBall, speedY * spinBall);*/
			double angle = atan2(speedY, speedX);
			std::cout << "angel " << angle << std::endl;// вычисляем угол направления в радианах
			double newAngle = angle + tan(angle); // вычисляем новый угол, увеличивая его на тангенс текущего угла
			double newSpeedX = cos(newAngle); // вычисляем новые значения скорости по осям X и Y
			double newSpeedY = sin(newAngle);
			shape.move(newSpeedX * spinBall, newSpeedY * spinBall); // перемещаем шарик



		}
		if (shape.getPosition().x >= paddle.shape.getPosition().x - shape.getRadius() && shape.getPosition().x <= paddle.shape.getPosition().x + paddle.shape.getSize().x + shape.getRadius() && shape.getPosition().y > paddle.shape.getPosition().y - paddle.shape.getSize().y - shape.getRadius() && shape.getPosition().y < paddle.shape.getPosition().y) {
			/*speedY *= -1;
			shape.move(speedX * spinBall, speedY * spinBall);*/


		}
		if (shape.getPosition().y > paddle.shape.getPosition().y) {
			isStart = false;
			paddle.shape.setPosition(paddle.GetPosX(), paddle.GetPosY());
			shape.setPosition(285, 765);
		}
	}
}

//void Ball::colossionWithBlock(std::vector<sf::RectangleShape>& blocks, sf::RenderWindow& window)
//{
//	for (unsigned k = 0; k < blocks.size(); k++) {
//		if (shape.getGlobalBounds().intersects(blocks[k].getGlobalBounds())) {
//			blocks.erase(blocks.begin() + k);
//			speedY *= -1;
//			shape.move(speedX, speedY); 
//			
//		}
//		
//	}
//	//blocks = blocks;
//}
void Ball::colossionWithBlock(std::vector<sf::RectangleShape>& blocks, sf::RenderWindow& window)
{
	for (unsigned k = 0; k < blocks.size(); k++) {
		if (shape.getGlobalBounds().intersects(blocks[k].getGlobalBounds())) {
			speedY = -speedY;
			//shape.move(speedX, speedY);
			blocks.erase(blocks.begin() + k);
		}

	}



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

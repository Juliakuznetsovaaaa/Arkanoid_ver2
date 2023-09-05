#pragma once
//
#include "Game.h"
#include <iostream>
#include <vector>
using namespace sf;


void movePaddleAndBall(int& p, Vector2f& paddleCoordinates, Paddle& paddle, Ball& ball, int windowWidth, float& paddelWeigth) {
	double spinBall = 1.52;
	if (Keyboard::isKeyPressed(Keyboard::Right))
		if (paddleCoordinates.x < windowWidth - paddelWeigth) {
			paddle.shape.move(spinBall, 0);
			if (p == 0)
				ball.shape.move(spinBall, 0);
		}

	if (Keyboard::isKeyPressed(Keyboard::Left))
		if (paddleCoordinates.x > 0) {
			paddle.shape.move(-spinBall, 0);
			if (p == 0)
				ball.shape.move(-spinBall, 0);
		}
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		p = 1;
	}
}

void moveBall(Ball& ball, Paddle& paddle, int& kx, int& ky, int& p) {
	if (ball.shape.getPosition().x < 0 || ball.shape.getPosition().x>580)
		kx = -kx;
	if (ball.shape.getPosition().y < 50)
		ky = -ky;
	//if (ball.shape.getPosition().x >= paddle.shape.getPosition().x - ball.shape.getRadius() && ball.shape.getPosition().x <= paddle.shape.getPosition().x + paddle.shape.getSize().x + ball.shape.getRadius() && ball.shape.getPosition().y > paddle.shape.getPosition().y - paddle.shape.getSize().y - ball.shape.getRadius() && ball.shape.getPosition().y < paddle.shape.getPosition().y) {
	if (ball.shape.getGlobalBounds().intersects(paddle.shape.getGlobalBounds())) {
		/*if (is_zaliz) {
				p = 0;
				is_zaliz = false;
			}
			if (spin != 0.2) {
				spin = 0.2;
			}*/
		ky = -ky;
	}

}

//void bonusBallActive(vector<BonusDrop>& bonusBall, bool& is_bonusBal, vector<bool>& is_active, Vector2f& paddleCoordinates, Paddle& paddle, float* delBrick, bool& is_zaliz, int& count, float& paddelWeigth, double& spin, VertexArray& line, bool& is_line, bool& is_change_position) {
//	int i = 0;
//	for (auto& bBall : bonusBall) {
//		if (is_active[i]) {
//			switch (bBall.getBonusType())
//			{
//			case 1:
//				spin = 0.1;
//				cout << "case1" << "\n";
//				break;
//			case 2:
//				paddle.shape.setSize(Vector2f(paddelWeigth + 30, 10));
//				cout << "case2" << "\n";
//				break;
//			case 3:
//				is_zaliz = true;
//				cout << "case3" << "\n";
//				break;
//			case 4:
//				line[0].color = Color::Red; // çàäàíèå öâåòà ïåðâîé âåðøèíû
//				line[1].color = Color::White; // çàäàíèå öâåòà âòîðîé âåðøèíû
//				is_line = true;
//				cout << "case4" << "\n";
//				break;
//			case 5:
//				is_change_position = true;
//				cout << "case5" << "\n";
//				break;
//			default:
//				break;
//			}
//			delBrick[0] = -1; delBrick[1] = -1; delBrick[2] = -1;
//			is_active[i] = false;
//		}
//		i++;
//	}
//
//
//
//
//}
//
//
bool delLife(Vector2f& ballCoordinates, Paddle& paddle, int& ky, int& kx, Ball& ball, int& p, int& l) {
	if (ballCoordinates.y > 890) {
		p = 0;
		ky = -ky;
		kx = -kx;
		ball.shape.setPosition(290, 770);
		paddle.shape.setPosition(paddle.getX(), paddle.getY());
		l++;
		return true;
	    //ball.life[l].setFillColor(Color::Transparent);
		

		/*if (!is_line) {

		}
		else {
			line[0].color = Color::Transparent;
			line[1].color = Color::Transparent;
			is_line = false;
		}
		score -= 1;
		text.setString("Score: " + std::to_string(score));*/
	}
	return false;
	/*if (l == -1) {
		q = 72;
		ball.shape.setFillColor(Color::Transparent);
		paddle.shape.setFillColor(Color::Transparent);
	}*/
}
//void updateBrickLevel(int brickLevel, Brick& brick) {
//	switch (brickLevel)
//	{
//	case 1:
//		brick.shape.setFillColor(Color(255, 168, 175, 255));
//		break;
//	case 2:
//		brick.shape.setFillColor(Color(255, 73, 108, 255));
//		break;
//	default:
//		break;
//	}
//}
void delBlock(Block& block, Ball& ball, std::vector<RectangleShape>& bricks, Vector2f& ballCoordinates, float* delBrick, int& kx, int& ky) {
	for (unsigned k = 0; k < bricks.size(); k++) {
		if (ball.shape.getGlobalBounds().intersects(bricks[k].getGlobalBounds())) {

			ky = -ky;
			if (block.processBlock(bricks[i]) {
				bricks.erase(bricks.begin() + k);
			}
			
		}

	}
	//Vector2f bl[72];
	//int i = 0;
	////cout << is_bonusBal << "\n";
	//for (auto& brick : bricks) {
	//	bl[i] = brick.shape.getPosition();

	//	if (ballCoordinates.x >= bl[i].x && ballCoordinates.x <= bl[i].x + 50)
	//		if (ballCoordinates.y <= bl[i].y + 50 && ballCoordinates.y >= bl[i].y) {
	//			ky = -ky;
	//			/*if (brick.getLevel() == 1) {
	//				brick.minLevel();
	//				Color bBallColor = brick.shape.getFillColor();
	//				score++;
	//				text.setString("Score: " + std::to_string(score));

	//				delBrick[0] = brick.shape.getPosition().x;
	//				delBrick[1] = brick.shape.getPosition().y;
	//				delBrick[2] = brick.getBonusType();*/
	//				brick.shape.setPosition(1200, 1200);
	//				/*if (delBrick[2] > 0) {
	//					bonusBall.emplace_back(delBrick[0], delBrick[1], bBallColor, delBrick[2]);
	//					is_active.push_back(false);
	//					count++;
	//					cout << count;
	//					bonusBall[count].shape.move(0, 0.3);
	//					is_bonusBal = true;
	//				}
	//			}
	//			else {
	//				brick.minLevel();
	//				updateBrickLevel(brick.getLevel(), brick);
	//				kx = -kx;
	//			}*/
	//		}
	//	i++;
	//}
}
//void bonusBallmove(vector<BonusDrop>& bonusBall, bool& is_bonusBal, vector<bool>& is_active, Vector2f& paddleCoordinates, Paddle& paddle, float* delBrick, bool& is_zaliz, int& count, float& paddelWeigth, double& spin, VertexArray& line, bool& is_line, bool& is_change_position) {
//	int i = 0;
//
//	for (auto& bBall : bonusBall) {
//
//		Vector2f bB = bBall.shape.getPosition();
//		if (bB.x >= paddleCoordinates.x && bB.x <= (paddleCoordinates.x + paddelWeigth) && bB.y > 710 && bB.y < 714) {
//			bBall.shape.setPosition(1200, 1200);
//			is_active[i] = true;
//			cout << " this is active " << i << "\n";
//		}
//		i++;
//
//	}
//}
Game::Game()
{
	score = 0;

	/*Field field;
	Paddle paddle;
	Ball ball;*/
	field.generateField(field.blocks);
}
int Game::start() {

	setlocale(LC_ALL, "Russian");

	unsigned int windowWidth = 600, windowHeight = 800;
	std::vector<sf::RectangleShape> bricks;
	
	int l = 0; int p = 0; int q = 0; int count = 0;
	
	float delBrick[] = { -1, -1, -1 };
	int score = 0;
	double spin = 1.2;
	float paddelWeigth = 200;
	int ky = -1;
	int kx = -1;
	sf::RenderWindow window(sf::VideoMode(600, 900), "Arcanoid");
	Paddle paddle;

	
	
	
	Ball ball;
	Field field;

	field.generateLife();


	

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		Vector2f m = paddle.shape.getPosition();
		if (q != 72) {
			movePaddleAndBall(p, m, paddle, ball, windowWidth, paddelWeigth);
		}
		else {
			p = 0;
		}
		if (p == 1&&l!=3) {
			ball.shape.move(spin * kx, spin * ky);
			Vector2f b = ball.shape.getPosition();
			
			moveBall(ball, paddle, kx, ky, p);
			//is_zaliz, count, paddelWeigth, spin, line, is_line, is_change_position);*/
			if (delLife(b, paddle, ky, kx, ball, p, l)) {
				
				field.delLife();
			}
			delBlock(ball, field.blocks, b, delBrick, kx, ky);
		}

		window.clear();
		for (auto& brick : field.blocks) window.draw(brick);
		for (auto& life : field.lifes) window.draw(life);

		window.draw(paddle.shape);
		window.draw(ball.shape);
		
		
		window.display();
	}
	return 0;
}




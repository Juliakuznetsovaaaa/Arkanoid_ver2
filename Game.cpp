#pragma once

#include "Game.h"
#include <iostream>

#define USER_WINDOW_WIDTH 650


Game::Game()
{
	score = 0;
	
	Field field;
	Paddle paddle;
	Ball ball;
}

int Game::start()
{
	sf::RenderWindow window(sf::VideoMode(600, 900), "Arcanoid");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				std::cout << "lol";
				window.close();
				
			}
				
		}

		window.clear();

		//window.draw(*field);
		//paddle->Draw(window);
		
		ball.move();
		for (auto& block : field.blocks) window.draw(&block.shape);
		window.draw(ball.shape);
		window.draw(paddle.shape);
		window.display();
		//paddle->Move(USER_WINDOW_WIDTH);
		//window->display();
	}
	return 0;
}

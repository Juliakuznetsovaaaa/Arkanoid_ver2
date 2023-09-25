#include"Field.h"
#include "Paddle.h"
#include "Ball.h"

class Game {
protected:
	int score;
	sf::RenderWindow window;
	Field field;
	Paddle paddle;
	Ball ball;
	Block block;
public:
	Game();
	~Game() {};
	int start();
};

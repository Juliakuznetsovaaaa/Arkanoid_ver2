#include"Field.h"
#include "../../Arkanoid/Arkanoid/Paddle.h"
#include "../../Arcanoid_try2/Arcanoid_try2/Ball.h"

class Game {
protected:
	int score;
	sf::RenderWindow window;
	Field field;
	Paddle paddle;
	Ball ball;
public:
	Game();
	~Game() {};
	int start();
};

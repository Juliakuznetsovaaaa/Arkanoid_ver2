#include "../../Arkanoid/Arkanoid/Paddle.h"
#include <SFML/Graphics.hpp>
#include <iostream>
class Bonus {
public:
	sf::CircleShape bonusBall;
	Bonus(float posX, float posY);
	sf::CircleShape getCircleShape() { return bonusBall; }
	~Bonus() {};
	virtual void active(sf::Vector2f& velocity) = 0;
};

class BallSpeed : public Bonus {
public:
	sf::CircleShape bonusBall;
	BallSpeed(float posX, float posY, float speedMultiplier) : Bonus(posX, posY), speedMultiplier(speedMultiplier) {}
	~BallSpeed() {};
	sf::CircleShape getCircleShape() { return bonusBall; }
	void active(sf::Vector2f& velocity) override; // переопределение функции-члена active() с аргументом Vector2f
private:
	float speedMultiplier;
};
class PaddelWidth : public Bonus {
public:
	sf::CircleShape bonusBall;
	PaddelWidth(float posX, float posY) : Bonus(posX, posY) {};
	sf::CircleShape getCircleShape() { return bonusBall; }
	void active(sf::Vector2f& velocity) override;
};
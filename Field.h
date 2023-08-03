#pragma once
#include "Block.h"

class Field {
protected:
	float width, height, offset;
	int blocksInRow, blocksInCol;
	sf::Color colorArray[4]{ sf::Color::Green, sf::Color::Red, sf::Color::Yellow, sf::Color::Blue };
public:
	std::vector<sf:: RectangleShape> blocks;
	Field();
	std::vector<sf::CircleShape> lifes;

	~Field() {};
	void generateField(std::vector<sf::RectangleShape>& blocks);
	void generateLife();
	void delLife();
	float getWidth();
	float getHeight();
	int getBlockInRow();
	int getBlockInCol();
	void setBlockType(sf::Color& blockColor, int& blockHealth);
};
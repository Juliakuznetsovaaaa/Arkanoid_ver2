#include "Field.h"
#define CHANCE 4

Field::Field()
{
	generateField(blocks);
}

void Field::generateField(std::vector<sf::RectangleShape>& blocks)
{
	//float blockHeight = height / blocksInCol;
	//float blockWidth = width / blocksInRow;
	float posX = 0, posY = 0;

	float blockHeight = 50;
	float blockWidth = 50;
	sf::Color blockColor=sf::Color::Blue;
	int blockHealth=1;

	for (auto i = 0; i < 8; i++)
		for (auto j = 0; j < 12; j++) {
			posX = j * 50;
			posY = i * 50;
			setBlockType(blockColor, blockHealth);
			Block newBlock(50, 50, posX, posY, blockHealth, blockColor);
			blocks.push_back(newBlock);
			/*Block(50, 50, posX, posY, blockHealth, blockColor);
			blocks.push_back(Block::shape);*/
		}
}
void Field::generateLife() {
	float radius = 15;
	for (auto i = 0; i < 3; i++) {
		sf::CircleShape life;
		life.setRadius(radius);
		life.setPosition(i * 2 * radius, radius);
		life.setColor(sf::Color::White);
		lifes.push_back(life);
	}
}

void Field::delLife()
{
	lifes.pop_back();
}


float Field::getWidth()
{
	return width;
}

float Field::getHeight()
{
	return height;
}

int Field::getBlockInRow()
{
	return blocksInRow;
}

int Field::getBlockInCol()
{
	return blocksInCol;
}

int Field::getHealthByColor(sf::Color color)
{
	switch (color) {
	case colorArray[0]:
		return -1;
	case colorArray[1]:
		return 1;
	case colorArray[2]:
		return 2; 
	case colorArray[3]:
			return 3;
	default:
		return 100;
	}
}

bool Field::isHealthZero(sf::RectangleShape& block)
{
	int health = getHealthByColor(sf::block.getFillColor());
	if (health < 0) {
		return false; 
	}
	if (health > 1) {
		sf::block.setFillColor(colorArray[health - 1]);
		return false;
	}
	return true;
}


void Field::setBlockType(sf::Color& blockColor, int& blockHealth)
{
	switch (rand() % CHANCE) {
	case 0:
		blockColor = colorArray[0];
		blockHealth = -1;
		break;
	case 1:
		blockColor = colorArray[1];
		blockHealth = 1;
		break;
	case 2:
		blockColor = colorArray[2];
		blockHealth = 2;
		break;
	default:
		blockColor = colorArray[3];
		blockHealth = 3;
	}
}

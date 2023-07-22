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

void Field::setBlockType(sf::Color& blockColor, int& blockHealth)
{
	switch (rand() % CHANCE) {
	case 0:
		blockColor = colorArray[0];
		blockHealth = 3;
		break;
	case 1:
		blockColor = colorArray[1];
		blockHealth = 2;
		break;
	case 2:
		blockColor = colorArray[2];
		blockHealth = 1;
		break;
	default:
		blockColor = colorArray[3];
		blockHealth = -1;
	}
}

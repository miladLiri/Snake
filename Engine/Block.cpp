#include "Block.h"


void Block::draw(Board& brd) const
{
	for (int i = 0; i < size; i++)
	{
		brd.draw(blocks[i], c);
	}
}

Location Block::newLocation(const Snake& snake, const Goal& goal, const Board& brd) const
{
	Location newLoc;

	do {
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> xDist(0, brd.getWidth() - 1);
		std::uniform_int_distribution<int> yDist(0, brd.getHeight() - 1);

		newLoc = { xDist(rng), yDist(rng) };

	} while (snake.isInTail(newLoc) || newLoc == goal.getLocation());

	return newLoc;
}

void Block::increase(const Snake& snake, const Goal& goal, const Board& brd)
{
	for (int i = 0; i < increaseValue; i++)
	{
		blocks[size] = newLocation(snake, goal, brd);
		size++;
	}
}

bool Block::collision(Snake& snake)
{
	Location sloc = snake.targetLocation();

	for (int i = 0; i < size; i++)
	{
		if (blocks[i] == sloc) {
			return true;
		}
	}
	return false;
}

void Block::reinit()
{
	size = 0;
}


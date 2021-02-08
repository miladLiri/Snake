#include "Goal.h"

Goal::Goal(const Board& brd, Snake& snake)
{
	relocate(brd,snake);
}

void Goal::draw(Board& brd) const
{
	brd.drawCirc(loc, color);
}


void Goal::relocate(const Board& brd, const Snake& snake)
{
	Location newLoc;

	do {
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> xDist(0, brd.getWidth() -1);
		std::uniform_int_distribution<int> yDist(0, brd.getHeight() -1);

		newLoc = { xDist(rng), yDist(rng) };

	} while (snake.isInTail(newLoc));

	loc = newLoc;
}

bool Goal::consumption(const Board& brd, Snake& snake)
{
	if (snake.isInTail(getLocation())) {
		relocate(brd, snake);
		snake.consumption();
		return true;
	}
	return false;
}

Location Goal::getLocation() const
{
	return loc;
}

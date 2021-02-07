#pragma once
#include "Location.h"
#include "Colors.h"
#include <random>
#include "Board.h"
#include "Snake.h"
#include "Goal.h"

class Block
{

private:

	static constexpr Color c = Colors::LightGray;
	static constexpr int maxSize = 30;
	Location blocks[maxSize];
	int size = 0;
	int increaseValue = 2;

public:

	void draw(Board& brd) const;
	Location newLocation(const Snake& snake, const Goal& goal, const Board& brd) const;
	void increase(const Snake& snake, const Goal& goal, const Board& brd);
	bool collision(Snake& snake);
	void reinit();

};
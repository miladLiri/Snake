#pragma once
#include "Location.h"
#include "Colors.h"
#include <random>
#include "Board.h"
#include "Snake.h"


class Goal
{

private:

	Location loc;
	Color color = Colors::Green;

public:

	Goal(const Board& brd,Snake& snake);
	void draw(Board& brd) const;
	void relocate(const Board& brd , const Snake& snake);
	bool consumption(const Board& brd, Snake& snake);
	Location getLocation() const;
};

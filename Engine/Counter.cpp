#include "Counter.h"

Counter::Counter(Graphics& gfx, int in_max)
	:
	gfx( gfx )
{
	maxLevel = in_max;
}

int Counter::getLevel() const
{
	return level;
}

void Counter::setLevel(const int in_level)
{
	if (in_level <= maxLevel) {
		level = in_level;
	}
}

void Counter::draw()
{
	const int levelHeight = ((gfx.ScreenHeight - 2 * (borderHeight + y) - levelPadding) / maxLevel) - levelPadding;
	const int bottom = gfx.ScreenHeight - y - borderHeight;
	
	gfx.DrowRect(x, y, width, borderHeight, color);
	gfx.DrowRect(x, bottom, width, borderHeight, color);

	for (int i = 0; i < level; i++)
	{
		gfx.DrowRect(x, bottom - levelHeight - i * (levelHeight + levelPadding) - levelPadding, width, levelHeight, color);
	}
}

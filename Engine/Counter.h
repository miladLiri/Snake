#pragma once
#include "Colors.h"
#include "Graphics.h"
class Counter 
{

private:

	int level = 0;
	int maxLevel;
	static constexpr int width = 26;
	static constexpr int borderHeight = 15;
	static constexpr int levelPadding = 2;
	static constexpr int x = 2;
	static constexpr int y = 10;
	Color color = Colors::Red;
	Graphics& gfx;

public:
	
	Counter(Graphics& gfx, int in_max);
	int getLevel() const;
	void setLevel(const int in_level);
	void draw();
};

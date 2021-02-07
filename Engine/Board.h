#pragma once

#include "Graphics.h"
#include "Location.h"

class Board 
{
	
public:

	Board(Graphics& gfx);
	int getWidth() const;
	int getHeight() const;
	void draw(const Location& loc, const Color c);
	void drawCirc(const Location& loc, const Color c);
	void drawBorder();
	void drawStart(const int x, const int y);
	void drawGameOver(const int x, const int y);
	void drawWin(const Location& loc, const Color c);

private:
	static constexpr int x = 110;
	static constexpr int y = 70;
	static constexpr int border = 10;
	static constexpr int dimantion = 20;
	static constexpr int width = 28;
	static constexpr int height = 23;
	Graphics& gfx;

};
#pragma once

#include "Graphics.h"
#include "Location.h"

class Board 
{
	
public:

	Board(Graphics& gfx);
	int getWidth() const;
	int getHeight() const;
	void drow(const Location& loc, const Color c);
	void drowCirc(const Location& loc, const Color c);
	void drowBorder();
	void drowStart(const int x, const int y);
	void drowGameOver(const int x, const int y);
	void drowWin(const Location& loc, const Color c);

private:
	static constexpr int x = 240;
	static constexpr int y = 120;
	static constexpr int border = 10;
	static constexpr int dimantion = 20;
	static constexpr int width = 18;
	static constexpr int height = 18;
	Graphics& gfx;

};
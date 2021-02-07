#pragma once

#include <random>
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Level1.h";

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	
private:
	MainWindow& wnd;
	Graphics gfx;

	enum status
	{
		WIN = 1,
		LOSE = -1,
		NOTFINISHED = 0,
	};

	int level = 1;

	Level1 level1;
};
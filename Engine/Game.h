#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include <random>
#include "Counter.h"

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

	//std::random_device rd;
	//std::mt19937 rng;
	Board brd;
	Snake snake;
	Goal goal;
	Counter counter;
	bool gameIsOver = false;
	bool gameIsStarted = false;
	bool win = false;
};
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include "Counter.h"

class Level1
{

private:

	MainWindow& wnd;
	Graphics& gfx;

	Board brd;
	Snake snake;
	Goal goal;
	Counter counter;

	bool gameIsStarted = false;

	enum status
	{
		WIN = 1,
		LOSE = -1,
		NOTFINISHED = 0,
	};

	status level = status::NOTFINISHED;

public:
	Level1(MainWindow& wnd, Graphics& gfx);
	void updateModel();
	void composeFrame();
	int status();


};
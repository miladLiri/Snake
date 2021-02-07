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
	bool gameIsOver = false;
	bool gameIsStarted = false;
	bool win = false;

public:
	Level1(MainWindow& wnd, Graphics& gfx);
	void composeFrame();
	void updateModel();



};
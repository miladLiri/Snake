
#include "MainWindow.h"
#include "Game.h"
#include <iostream>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	//rng( rd() )
	//rng(std::random_device()()),
	level1(wnd,gfx),
	level2(wnd,gfx)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (level1.status() == status::NOTFINISHED && level == 1)
	{
		level1.updateModel();
	}
	
	if (level == 1 && level1.status() == status::LOSE && wnd.kbd.KeyIsPressed( VK_RETURN ) )
	{
		level1.reinit();
	}

	if (level == 1 && level1.status() == status::WIN && wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		level++;
	}

	//level 2

	if (level2.status() == status::NOTFINISHED && level == 2)
	{
		level2.updateModel();
	}

	if (level == 2 && level2.status() == status::LOSE && wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		level1.reinit();
	}

	if (level == 2 && level2.status() == status::WIN && wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		level++;
	}
}

void Game::ComposeFrame()
{
	if (level == 1)
	{
		level1.composeFrame();
	}

	if(level == 2)
	{
		level2.composeFrame();
	}
	
}


#include "MainWindow.h"
#include "Game.h"
#include <iostream>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	//rng( rd() )
	//rng(std::random_device()()),
	level1(wnd,gfx)
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

	//level1.updateModel();
}

void Game::ComposeFrame()
{
	std::cout << "hello" << std::endl;
	//level1.composeFrame();
}

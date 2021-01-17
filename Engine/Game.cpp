
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	//rng( rd() )
	//rng(std::random_device()()),
	brd(gfx),
	snake({ 6,6 }),
	goal(brd,snake),
	counter(gfx, snake.getWinSize())
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

	if (gameIsStarted) {

		if (gameIsOver || win) {
			return;
		}

		goal.consumption(brd, snake);
		snake.update(wnd, brd);
		counter.setLevel(snake.getTailSize());

		if (snake.checkFinishRules(brd)) {
			gameIsOver = true;
		}

		if (snake.getTailSize() == snake.getWinSize()) {
			win = true;
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			gameIsStarted = true;
		}
	}
}

void Game::ComposeFrame()
{

	brd.drowBorder();
	counter.drow();

	if(gameIsStarted){

		snake.drow(brd);
		goal.draw(brd);
		
		if (gameIsOver)
		{
			brd.drowGameOver(350, 250);
		}

		if (win) {
			brd.drowWin({ 13,12 }, Colors::Yellow);
		}
	}
	else
	{
		brd.drowStart(300,200);
	}
}

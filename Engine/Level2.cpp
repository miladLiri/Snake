#include "Level2.h"

Level2::Level2(MainWindow& wnd, Graphics& gfx)
	:
	wnd(wnd),
	gfx(gfx),
	brd(gfx),
	snake(),
	goal(brd, snake),
	counter(gfx, snake.getWinSize())
{
	snake.config(8, true, false);
}

void Level2::updateModel()
{

	if (gameIsStarted) {

		if (level != status::NOTFINISHED)
		{
			return;
		}

		snake.update(wnd, brd);
		counter.setLevel(snake.getTailSize());

		if (goal.consumption(brd, snake))
		{
			block.increase(snake,goal,brd);
		}

		if (block.collision(snake)) {
			level = status::LOSE;
		}

		if (snake.checkFinishRules(brd)) {
			level = status::LOSE;
		}

		if (snake.getTailSize() == snake.getWinSize()) {
			level = status::WIN;
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			gameIsStarted = true;
		}
	}

}

void Level2::composeFrame()
{
	brd.drawBorder();
	counter.draw();

	if (gameIsStarted) {

		brd.drawTitleLevel2({ 30,9 }, Colors::Yellow);
		snake.draw(brd);
		goal.draw(brd);
		block.draw(brd);

		if (level == status::LOSE)
		{
			brd.drawGameOver(350, 250);
		}

		if (level == status::WIN) {
			brd.drawWin({ 8,10 }, Colors::Yellow);
		}
	}
	else
	{
		brd.drawTitleLevel2({ 13,9 }, Colors::Yellow);
	}
}

int Level2::status()
{
	switch (level)
	{

	case Level2::WIN:
		return status::WIN;
		break;

	case Level2::LOSE:
		return status::LOSE;
		break;

	case Level2::NOTFINISHED:
		return status::NOTFINISHED;
		break;
	}
}

void Level2::reinit()
{
	snake.reinit(8,true,false);
	block.reinit();
	gameIsStarted = false;
	level = status::NOTFINISHED;
}

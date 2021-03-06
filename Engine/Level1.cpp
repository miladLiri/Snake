#include "Level1.h"

Level1::Level1(MainWindow& wnd, Graphics& gfx)
	:
	wnd(wnd),
	gfx(gfx),
	brd(gfx),
	snake(),
	goal(brd, snake),
	counter(gfx, snake.getWinSize())
{
	snake.config(15, false, true);
}

void Level1::updateModel()
{

	if (gameIsStarted) {

		if (level != status::NOTFINISHED)
		{
			return;
		}

		goal.consumption(brd, snake);
		snake.update(wnd, brd);
		counter.setLevel(snake.getTailSize());

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

void Level1::composeFrame()
{
	brd.drawBorder();
	counter.draw();

	if (gameIsStarted) {

		brd.drawTitleLevel1({ 30,9 }, Colors::Yellow);
		snake.draw(brd);
		goal.draw(brd);

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
		brd.drawTitleLevel1({ 14,9 }, Colors::Yellow);
	}
}

int Level1::status()
{
	switch (level)
	{

	case Level1::WIN:
		return status::WIN;
		break;

	case Level1::LOSE:
		return status::LOSE;
		break;

	case Level1::NOTFINISHED:
		return status::NOTFINISHED;
		break;
	}
}

void Level1::reinit()
{
	snake.reinit(15, false, true);
	gameIsStarted = false;
	level = status::NOTFINISHED;
}

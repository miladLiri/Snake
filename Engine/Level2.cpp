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
	snake.config(5, true, false);
}

void Level2::updateModel()
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

void Level2::composeFrame()
{
	brd.drowBorder();
	counter.drow();

	if (gameIsStarted) {

		snake.drow(brd);
		goal.draw(brd);

		if (level == status::LOSE)
		{
			brd.drowGameOver(350, 250);
		}

		if (level == status::WIN) {
			brd.drowWin({ 13,12 }, Colors::Yellow);
		}
	}
	else
	{
		brd.drowStart(300, 200);
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
	snake.reinit();
	gameIsStarted = false;
	level = status::NOTFINISHED;
}

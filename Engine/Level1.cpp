#include "Level1.h"

Level1::Level1(MainWindow& wnd, Graphics& gfx)
	:
	wnd(wnd),
	gfx(gfx),
	brd(gfx),
	snake({ 6,6 }),
	goal(brd, snake),
	counter(gfx, snake.getWinSize())
{
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
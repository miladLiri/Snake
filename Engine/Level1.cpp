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

void Level1::composeFrame()
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

void Level1::updateModel()
{

	brd.drowBorder();
	counter.drow();

	if (gameIsStarted) {

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
		brd.drowStart(300, 200);
	}
}

#include "Snake.h"
#include <assert.h>

Snake::Snake()
{
	segments[0].initHead(initLocation);
}

void Snake::drow(Board& brd) const
{
	
	for (int i = 0; i < size; i++)
	{
		segments[i].drow(brd);
	}
}

void Snake::move()
{
	assert(abs(delta.x) + abs(delta.y) == 1);

	for (int i = size-1 ; i > 0; i--)
	{
		segments[i].follow(segments[i - 1]);
	}

	segments[0].move(delta);
}

void Snake::grow()
{
	if (size < maxSegment) {
		segments[size].initBody(size);
		size++;

		if (speedRising && moveFrameRate > 3) {
			moveFrameRate--;
		}
	}
}

void Snake::control(const MainWindow& wnd)
{

	if (wnd.kbd.KeyIsPressed( VK_UP ) && (delta.y != 1  || size == 1))
	{
		delta = { 0,-1 };
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN) && (delta.y != -1 || size == 1))
	{
		delta = { 0,1 };
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT) && (delta.x != -1 || size == 1))
	{
		delta = { 1,0 };
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT) && (delta.x != 1 || size == 1))
	{
		delta = { -1,0 };
	}

	

}

Location Snake::targetLocation() const
{
	Location l(segments[0].getLocation());
	l.add(delta);
	return l;
}

Location Snake::targetLocation(Segment& segment) const
{
	assert(segment.getIndex() != 0);
	return segments[segment.getIndex() - 1].getLocation();
}

bool Snake::checkWallColliding(const Board& brd) const
{
	Location target = targetLocation();

	return
		target.x < -1 ||
		target.y < -1 ||
		target.x >= brd.getWidth() + 1  ||
		target.y >= brd.getHeight() + 1;
}

int Snake::checkSelfColliding()
{
	const Location target = targetLocation();

	for (int i = 2; i < size - 1; i++)
	{
		if (segments[i].getLocation() == target) {
			return i;
		}
	}
	return 0;
}

bool Snake::isInTail(const Location& loc) const
{
	for (int i = 0; i < size; i++)
	{
		if (segments[i].getLocation() == loc) {
			return true;
		}
	}
	return false;
}

void Snake::consumption()
{
	checkGoalConsumption = true;
}

void Snake::selfCollision()
{
	int index = checkSelfColliding();
	if (index) {
		size = index;
	}
}

bool Snake::checkFinishRules(const Board& brd)
{
	bool selfCollision = checkSelfColliding();

	if (allowSelfCollision) {
		selfCollision = false;
	}

	return
		selfCollision ||
		checkWallColliding(brd);
}

int Snake::getWinSize() const
{
	return maxSegment -1;
}

int Snake::getTailSize() const
{
	return size -1;
}

void Snake::reinit()
{
	size = 1;
	segments[0].setLocation(initLocation);
}

void Snake::config(const int mvFrmRt, const bool AlSlfClsn, const bool SpdRsng)
{
	moveFrameRate = mvFrmRt;
	allowSelfCollision = AlSlfClsn;
	speedRising = SpdRsng;
}



void Snake::update(const MainWindow& wnd, const Board& brd)
{
	frameCounter++;
	
	if (frameCounter >= moveFrameRate) {

		frameCounter = 0;
		

		control(wnd);

		if (checkGoalConsumption) {
			checkGoalConsumption = false;
			grow();
		}

		if (allowSelfCollision) {
			selfCollision();
		}

		if (!checkFinishRules(brd)){
			move();
		}
	}
}




void Snake::Segment::initHead(const Location& in_loc)
{
	loc = in_loc;
	color = headColor;
	index = 0;
}

void Snake::Segment::initBody(int in_index)
{
	color = bodyColor1;
	index = in_index;
}

void Snake::Segment::drow(Board& brd) const
{
	brd.drow(loc, color);
}

void Snake::Segment::move(const Location& delta)
{
	loc.add(delta);
}

void Snake::Segment::follow(const Segment& next) 
{
	loc = next.loc;
}

Location Snake::Segment::getLocation() const
{
	return loc;
}

int Snake::Segment::getIndex() const
{
	return index;
}

void Snake::Segment::setLocation(const Location& in_loc)
{
	loc = in_loc;
}

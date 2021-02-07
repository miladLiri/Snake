#pragma once
#include "Colors.h"
#include "Location.h"
#include "board.h"
#include "MainWindow.h"

class Snake {

private:
	class Segment {

	private:

		Location loc;
		Color color;
		int index;

	public:

		void initHead(const Location& in_loc);
		void initBody(int in_index);
		void drow(Board& brd) const;
		void move(const Location& delta);
		void follow(const Segment& next);
		Location getLocation() const;
		int getIndex() const;
		void setLocation(const Location& in_loc);
	};

private:

	static constexpr Location initLocation = {6 , 6};
	static constexpr int maxSegment = 6;
	Segment segments[maxSegment];
	int size = 1;
	static constexpr Color headColor = Colors::Blue;
	static constexpr Color bodyColor1 = Colors::Cyan;
	static constexpr Color bodyColor2 = Colors::Blue;
	Location delta = { 1,0 };
	static constexpr int moveFrameRate = 5;
	int frameCounter = 0;
	bool checkGoalConsumption = false;
	bool allowSelfCollision = true;
	bool isDeltaChanged = false;

public:

	Snake();
	void drow(Board& brd) const;
	void move();
	void grow();
	void control(const MainWindow& wnd);
	void update(const MainWindow& wnd, const Board& brd);
	Location targetLocation() const;
	Location targetLocation(Segment& segment) const;
	bool checkWallColliding(const Board& brd) const;
	int checkSelfColliding();
	bool isInTail(const Location& loc) const;
	void consumption();
	void selfCollision();
	bool checkFinishRules(const Board& brd);
	int getWinSize() const;
	int getTailSize() const;
	void reinit();
};

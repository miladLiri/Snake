#pragma once

class Location
{

public:

	void add(const Location& delta) {
		x += delta.x;
		y += delta.y;
	}

	bool operator == (const Location loc) const {
		return x == loc.x && y == loc.y;
	}

	int x;
	int y;

};


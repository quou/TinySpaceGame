/* TinySpaceGame
	by George Lamb
	started: 1/04/2020
*/

#pragma once
struct Collider
{
	int x, y, w, h;

	Collider()
		:
		x(0),
		y(0),
		w(0),
		h(0)
	{}

	Collider(int x, int y, int w, int h)
		:
		x(x),
		y(y),
		w(w),
		h(h)
	{}

	bool MeetingCheck(Collider& other)
	{
		if (
			this->x < other.x + other.w &&
			this->x + this->w > other.x &&
			this->y < other.y + other.h &&
			this->y + this->h > other.y
			)
		{
			return true;
		}
		return false;
	}
};


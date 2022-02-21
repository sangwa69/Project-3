#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp
void Peach::goTo(double dest_x, double dest_y) {
	if (getWorld()->isValidPos(dest_x, dest_y))
		moveTo(dest_x, dest_y);
}

void Peach::doSomething() {
	int ch;
	if (getWorld()->getKey(ch))
	{

		switch (ch)
		{
		case KEY_PRESS_LEFT:
			goTo(getX() - 4, getY());
			break;
		case KEY_PRESS_RIGHT:
			goTo(getX() + 4, getY());
			break;
		case KEY_PRESS_UP:
			goTo(getX(), getY() + 4);
			break;
		case KEY_PRESS_DOWN:
			goTo(getX(), getY() - 4);
			break;
		default:
			break;
		}
	}
	return;
}

#include "point.h"

point::point()
{
	x = 1;
	y = 1;
}

point::point(int newX, int newY)
{
	x = newX;
	y = newY;

}

int point::getXPoint()
{
	return x;
}

int point::getYPoint()
{
	return y;
}

void point::setXPoint(int newX)
{
	x = newX;
}

void point::setYPoint(int newY)
{
	y = newY;
}
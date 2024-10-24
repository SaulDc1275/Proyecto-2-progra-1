#include "Coordinate.h"

Coordinate::Coordinate()
{
	x = 0;
	y = 0;
	circle.setRadius(10);
	circle.setPosition(x, y);  // Posicionar el círculo
	circle.setFillColor(Color::Red);
}

Coordinate::Coordinate(int x, int y)
{
	this->x = x;
	this->y = y;
	circle.setRadius(10);
	circle.setPosition(x, y);
	circle.setFillColor(Color::Red);
}

int Coordinate::getX() const {
	return x;
}

int Coordinate::getY() const {
	return y;
}

const CircleShape& Coordinate::getCircle() const
{
	return circle;
}

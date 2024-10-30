#include "Coordinate.h"

Coordinate::Coordinate()
{
	x = 0;
	y = 0;
	
}

Coordinate::Coordinate(int x, int y)
{
	this->x = x;
	this->y = y;
	
}

int Coordinate::getX() const {
	return x;
}

int Coordinate::getY() const {
	return y;
}

void Coordinate::setName(string name)
{
	this->name = name;
}

string Coordinate::getName()
{
	return name;
}

Coordinate::~Coordinate()
{

}



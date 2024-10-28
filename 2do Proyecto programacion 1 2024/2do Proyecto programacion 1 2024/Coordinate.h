#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Coordinate
{
private:
	int x;
	int y;
	
public:
	Coordinate();
	Coordinate(int x, int y);
	int getX() const;
	int getY() const;
	
};


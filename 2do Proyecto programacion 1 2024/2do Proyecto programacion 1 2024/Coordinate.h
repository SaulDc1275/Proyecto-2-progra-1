#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Coordinate
{
private:
	int x;
	int y;
	string name;
public:
	Coordinate();
	Coordinate(int x, int y);
	int getX() const;
	int getY() const;
	void setName(string name);
	string getName();
	~Coordinate();
};


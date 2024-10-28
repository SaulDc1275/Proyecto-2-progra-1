#pragma once
#include "Node.h"
#include <SFML/Graphics.hpp>
#include "Coordinate.h"
using namespace sf;

class Route
{
public:
	Color color;
	int size;
	bool isDrawn;
	Node<Coordinate>* first;
	Node<Coordinate>* last;
	Route();
	void insertLast(Coordinate newValue);
	void DrawRoute(RenderWindow& window);
	//void DeleteAtPosition(Vector2f mousePos);
    
};


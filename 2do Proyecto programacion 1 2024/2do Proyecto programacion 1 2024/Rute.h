#pragma once
#include "Node.h"
#include <SFML/Graphics.hpp>
#include "Coordinate.h"
using namespace sf;

class Rute
{

public:
	Node<Coordinate>* first;
	Node<Coordinate>* last;
	Rute() : first(nullptr), last(nullptr) {};
	void insertLast(Coordinate newValue);
	void DrawList(RenderWindow& window);
	void DeleteAtPosition(Vector2f mousePos);
    
};


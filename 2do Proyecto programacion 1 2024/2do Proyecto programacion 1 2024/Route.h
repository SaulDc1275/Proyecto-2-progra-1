#pragma once
#include "Node.h"
#include <SFML/Graphics.hpp>
#include "Coordinate.h"
using namespace sf;

class Route
{
public:
	CircleShape point;
	Color color;
	int size;
	Node<Coordinate>* first;
	Node<Coordinate>* last;
	Route();
	void insertLast(Coordinate newValue);
	void DrawRoute(RenderWindow& window);
	void DeleteAPoint(Vector2f mousePos);
	void DrawBSpline(RenderWindow& window);
	Vector2f DeBoor(float t, int d, int p, float knotVector[]);
	~Route();

};


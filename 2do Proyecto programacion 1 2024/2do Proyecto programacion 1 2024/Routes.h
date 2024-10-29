#pragma once
#include "Route.h"

class Routes
{
public:
    Node<Route>* first;
    Node<Route>* last;
    int size;

    Routes() : first(nullptr), size(0) {}
    void addRoute(Route& route);
    void Draw(RenderWindow& window);
    void DeleteCurrentRoute(Node<Route>*& activeRoute);
};


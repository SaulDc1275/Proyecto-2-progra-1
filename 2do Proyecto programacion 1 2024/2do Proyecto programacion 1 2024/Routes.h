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
    void DrawRoutes(RenderWindow& window, Node<Route>* activeRoute);
    void DeleteCurrentRoute(Node<Route>*& activeRoute);
};


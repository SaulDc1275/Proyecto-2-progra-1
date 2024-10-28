#include "Routes.h"

void Routes::addRoute(Route& route)
{
    if (first  == nullptr) {
        first = new Node<Route>(route);
    }
    else {
        Node<Route>* temp = first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node<Route>(route);
    }
    size++;
}

void Routes::Draw(RenderWindow& window)
{
    Node<Route>* temp = first;
    while (temp != nullptr) {
        temp->value.DrawRoute(window);
        temp = temp->next;
    }
}


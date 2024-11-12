#include "Routes.h"

void Routes::addRoute(Route& route)
{
    Node<Route>* newNode = new Node<Route>(route);
    if (first  == nullptr) {
        first = newNode;
        last = newNode;
    }
    else {
        last ->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
    size++;
}

void Routes::DrawRoutes(RenderWindow& window, Node<Route>* activeRoute) {
    Node<Route>* temp = first;
    float y = 0;
    Font font;
    font.loadFromFile("Fuentes/Retro_Gaming.ttf");

    while (temp != nullptr) {
        temp->value.DrawRoute(window);

        Text routeNameText;
        routeNameText.setFont(font);
        routeNameText.setString(temp->value.name);
        routeNameText.setCharacterSize(15);

 
        if (temp == activeRoute) {
            routeNameText.setFillColor(Color::Cyan);
            routeNameText.setCharacterSize(15);
            routeNameText.setStyle(Text::Bold);
        }
        else {
            routeNameText.setFillColor(temp->value.color);
            routeNameText.setCharacterSize(15);
        }


        routeNameText.setPosition(290, 10 + y);

        window.draw(routeNameText);

        y += 20;

        temp = temp->next;
    }
}




void Routes::DeleteCurrentRoute(Node<Route>*& activeRoute) {
    if (activeRoute == nullptr) {
        printf("No hay una ruta activa para eliminar.\n");
        return;
    }

    Node<Route>* temp = activeRoute;

    if (temp == first) {
        first = temp->next;
        if (first != nullptr) {
            first->prev = nullptr;
        }
        else {
            last = nullptr;
        }
    }
    else {
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        else {
            last = temp->prev;
        }
    }
    delete temp;
    size--;
}




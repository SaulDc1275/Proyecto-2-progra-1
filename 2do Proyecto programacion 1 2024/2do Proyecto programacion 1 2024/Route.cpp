#include "Route.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

using namespace std;
Route::Route()
{
    first = nullptr;
    last = nullptr;
    size = 0;
    color = Color::White;
    point.setRadius(7);
}

void Route::insertLast(Coordinate newValue) {
	Node<Coordinate>* newNode = new Node<Coordinate>(newValue);
	if (first == nullptr) {
		first = newNode;
		last = newNode;
	}
	else {
		last->next = newNode;
		newNode->prev = last;
		last = newNode;
	}
    size++;
}

void Route::DrawRoute(RenderWindow& window) {
    Font font;
    font.loadFromFile("Fuentes/Retro_Gaming.ttf");

    Node<Coordinate>* current = first;
    while (current != nullptr) {
        point.setFillColor(color);
        point.setPosition(current->value.getX() - 3, current->value.getY() - 3);
        

        if (current->next != nullptr) {
            Vector2f start(current->value.getX(), current->value.getY());
            Vector2f end(current->next->value.getX(), current->next->value.getY());

            VertexArray curve(LinesStrip, 10);
            for (int i = 0; i < 10; i++) {
                float t = i / 9.0f;
                float x = (1 - t) * start.x + t * end.x;
                float y = (1 - t) * start.y + t * end.y - sin(t * 3.14) * 20;
                curve[i].position = Vector2f(x, y);
                curve[i].color = color;
            }

            window.draw(curve);
        }
        window.draw(point);


        Text text;
        text.setFont(font);
        text.setString(current->value.getName());
        text.setCharacterSize(15);
        text.setFillColor(color);
        text.setPosition(current->value.getX() - 20 , current->value.getY() - 20);

        window.draw(text);

        current = current->next;
    }
    
}

void Route::DeleteAPoint(Vector2f mousePos) {
    Node<Coordinate>* current = first;

    while (current != nullptr) {
    point.setPosition(static_cast<float>(current->value.getX()), static_cast<float>(current->value.getY()));

        if (point.getGlobalBounds().contains(mousePos)) {
            if (current == first) {
                first = current->next;
                if (first != nullptr) {
                    first->prev = nullptr;
                }
                else {
                    last = nullptr;
                }
            }
            else if (current == last) {
                last = current->prev;
                if (last != nullptr) {
                    last->next = nullptr;
                }
                else {
                    first = nullptr;
                }
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            size--;
            return;
        }
        current = current->next;
    }
    
}

Route::~Route() {
    Node<Coordinate>* current = first;  // Comenzamos en el primer nodo
    while (current != nullptr) {
        Node<Coordinate>* nextNode = current->next;  // Guardamos el siguiente nodo
        delete current;  // Eliminamos el nodo actual
        current = nextNode;  // Pasamos al siguiente nodo
    }
}

#include "Route.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Route::Route()
{
    first = nullptr;
    last = nullptr;
    size = 0;
    color = Color::White;
    isDrawn = false;
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
    if (!isDrawn) { return; }

    Node<Coordinate>* current = first;
    while (current != nullptr) {
       
        CircleShape point(10);
        point.setFillColor(color);
        point.setPosition(current->value.getX(), current->value.getY());
        window.draw(point); 

        
        if (current->next != nullptr) {
            Vertex line[] = {
                Vertex(Vector2f(current->value.getX(), current->value.getY())),
                Vertex(Vector2f(current->next->value.getX(), current->next->value.getY()))
            };
            window.draw(line, 2, Lines);  
        }

        window.draw(point);
        current = current->next;
    }
}



    




//void Route::DeleteAtPosition(Vector2f mousePos) {
//    Node<Coordinate>* actual = first;
//
//    while (actual != nullptr) {
//        // Comprobar si el mouse está dentro de este círculo
//        if (actual->value.getCircle().getGlobalBounds().contains(mousePos)) {
//            // Si el nodo a eliminar es el primero
//            if (actual == first) {
//                first = actual->next; // Mover el inicio de la lista
//                if (first != nullptr) {
//                    first->prev = nullptr; // El nuevo primer nodo no tiene anterior
//                }
//            }
//            // Si el nodo a eliminar es el último
//            else if (actual == last) {
//                last = actual->prev; // Mover el final de la lista
//                if (last != nullptr) {
//                    last->next = nullptr; // El nuevo último nodo no tiene siguiente
//                }
//            }
//            // Si el nodo a eliminar está en el medio
//            else {
//                actual->prev->next = actual->next; // El nodo anterior apunta al siguiente
//                actual->next->prev = actual->prev; // El nodo siguiente apunta al anterior
//            }
//
//            delete actual; // Liberar la memoria del nodo
//            return; // Salir de la función, círculo eliminado
//        }
//        actual = actual->next; // Avanzar al siguiente nodo
//    }
//}

#include "Rute.h"
#include <SFML/Graphics.hpp>
using namespace sf;

void Rute::insertLast(Coordinate newValue) {
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
}


void Rute::DrawList(RenderWindow& window) {
	Node<Coordinate>* actual = first;
	while (actual) {
		window.draw(actual->value.getCircle());
		actual = actual->next;
	}
}


void Rute::DeleteAtPosition(Vector2f mousePos) {
    Node<Coordinate>* actual = first;

    while (actual != nullptr) {
        // Comprobar si el mouse est� dentro de este c�rculo
        if (actual->value.getCircle().getGlobalBounds().contains(mousePos)) {
            // Si el nodo a eliminar es el primero
            if (actual == first) {
                first = actual->next; // Mover el inicio de la lista
                if (first != nullptr) {
                    first->prev = nullptr; // El nuevo primer nodo no tiene anterior
                }
            }
            // Si el nodo a eliminar es el �ltimo
            else if (actual == last) {
                last = actual->prev; // Mover el final de la lista
                if (last != nullptr) {
                    last->next = nullptr; // El nuevo �ltimo nodo no tiene siguiente
                }
            }
            // Si el nodo a eliminar est� en el medio
            else {
                actual->prev->next = actual->next; // El nodo anterior apunta al siguiente
                actual->next->prev = actual->prev; // El nodo siguiente apunta al anterior
            }

            delete actual; // Liberar la memoria del nodo
            return; // Salir de la funci�n, c�rculo eliminado
        }
        actual = actual->next; // Avanzar al siguiente nodo
    }
}

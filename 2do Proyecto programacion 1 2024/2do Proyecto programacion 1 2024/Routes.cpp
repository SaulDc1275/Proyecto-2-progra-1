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

void Routes::Draw(RenderWindow& window)
{
    Node<Route>* temp = first;
    while (temp != nullptr) {
        temp->value.DrawRoute(window);
        //temp->value.DrawBSpline(window);
        temp = temp->next;
    }
}



void Routes::DeleteCurrentRoute(Node<Route>*& activeRoute) {
    if (activeRoute == nullptr) { // Verifica si hay un nodo activo
        printf("No hay una ruta activa para eliminar.\n");
        return;
    }

    // El nodo a eliminar
    Node<Route>* temp = activeRoute;

    // Si el nodo a eliminar es el primero
    if (temp == first) {
        first = temp->next; // Mueve el inicio de la lista
        if (first != nullptr) {
            first->prev = nullptr; // Ajustar el puntero anterior si hay un nuevo primer nodo
        }
        else {
            last = nullptr; // Si la lista queda vacía, también actualiza last
        }
    }
    else {
        // Conectar el nodo anterior y el siguiente
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next; // Conectar el anterior
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev; // Conectar el siguiente
        }
        else {
            last = temp->prev; // Si el nodo a eliminar es el último, actualizar last
        }
    }

    delete temp;
    size--;
}




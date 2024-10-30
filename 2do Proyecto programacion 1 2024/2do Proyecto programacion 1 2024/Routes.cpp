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
        // Crear el texto para el nombre de la ruta
        Text routeNameText;
        routeNameText.setFont(font);
        routeNameText.setString(temp->value.name);
        routeNameText.setCharacterSize(15);

        // Verificar si es la ruta activa
        if (temp == activeRoute) {
            routeNameText.setFillColor(Color::Cyan); // Color especial para la ruta activa
            routeNameText.setCharacterSize(15);        // Tamaño más grande para la ruta activa
            routeNameText.setStyle(Text::Bold);        // Estilo en negrita para la ruta activa
        }
        else {
            routeNameText.setFillColor(temp->value.color);  // Color normal para rutas inactivas
            routeNameText.setCharacterSize(15);        // Tamaño normal para rutas inactivas
        }

        // Establecer la posición en la esquina superior derecha del mapa
        routeNameText.setPosition(290, 10 + y);

        // Dibujar el texto en la ventana
        window.draw(routeNameText);

        // Aumentar el desplazamiento vertical para la siguiente ruta
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




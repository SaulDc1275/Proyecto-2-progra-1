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
    color = Color::Black;
   
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
            Vertex line[] = {
                Vertex(Vector2f(current->value.getX(), current->value.getY())),
                Vertex(Vector2f(current->next->value.getX(), current->next->value.getY()))
            };
            window.draw(line, 2, Lines);
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

//void Route::DrawBSpline(RenderWindow& window) {
//    int n = size;
//    if (n < 4) {
//        // Se necesitan al menos 4 puntos para calcular una B-Spline
//        return;
//    }
//
//    // Definimos el número de segmentos que deseamos dibujar
//    int segments = 100; // Más segmentos resultan en una curva más suave
//
//    // Coeficientes de la base B-Spline (de grado 3)
//    // Debemos establecer estos coeficientes de manera apropiada para la B-Spline cúbica
//    float knotVector[] = { 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4 }; // Ejemplo para 7 puntos de control
//    float delta = 1.0f / segments; // Incremento para cada segmento
//
//    // Creamos un array de coordenadas para los puntos a dibujar
//    VertexArray splinePoints(LinesStrip, segments + 1); // Usamos LinesStrip para conectar los puntos
//
//    // Iteramos a través de los segmentos
//    for (int i = 0; i <= segments; ++i) {
//        float t = i * delta; // Calculamos el valor de t para cada segmento
//
//        // Usamos el algoritmo de De Boor para calcular el punto en la curva B-Spline
//        Vector2f point = DeBoor(t, n - 1, 3, knotVector);
//
//        // Almacenamos el punto en el array
//        splinePoints[i].position = point;
//        splinePoints[i].color = color; // Establecer el color de la línea
//    }
//
//    // Dibujamos la curva B-Spline
//    window.draw(splinePoints);
//}
//
//// Función para calcular el punto en la curva B-Spline usando el algoritmo de De Boor
//Vector2f Route::DeBoor(float t, int d, int p, float knotVector[]) {
//    // Encontrar el índice del primer knot en el que se debe calcular
//    int k = p; // Este es el índice de la base que usamos en la B-Spline
//    while (k < p + d && t >= knotVector[k + 1]) {
//        k++;
//    }
//
//    // Crear un vector para almacenar los puntos de control
//    Node<Coordinate>* current = first;
//    Vector2f* controlPoints = new Vector2f[p + 1];
//
//    // Rellenar los puntos de control
//    for (int i = 0; i <= p; ++i) {
//        if (current != nullptr) {
//            controlPoints[i] = Vector2f(current->value.getX(), current->value.getY());
//            current = current->next;
//        }
//    }
//
//    // Algoritmo de De Boor
//    for (int r = 1; r <= p; ++r) {
//        for (int j = p; j >= r; --j) {
//            float alpha = (t - knotVector[j]) / (knotVector[j + 1 + p - r] - knotVector[j]);
//            controlPoints[j] = (1.0f - alpha) * controlPoints[j - 1] + alpha * controlPoints[j];
//        }
//    }
//
//    Vector2f result = controlPoints[p];
//    delete[] controlPoints; // Liberar la memoria
//    return result;
//}

Route::~Route() {
    Node<Coordinate>* current = first;  // Comenzamos en el primer nodo
    while (current != nullptr) {
        Node<Coordinate>* nextNode = current->next;  // Guardamos el siguiente nodo
        delete current;  // Eliminamos el nodo actual
        current = nextNode;  // Pasamos al siguiente nodo
    }
}

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

void Routes::SaveToFile() {

    ofstream File("Archivos//Rutas.txt");

    if (!File) {
        cerr << "Error al abrir el archivo para guardar." << endl;
        return;
    }

    Node<Route>* currentRoute = first;
    while (currentRoute != nullptr) {

        File << "Ruta: " << currentRoute->value.name << endl;
        File << "Color: " << (int)currentRoute->value.color.r << " " << (int)currentRoute->value.color.g << " " << (int)currentRoute->value.color.b << " " << endl;

        Node<Coordinate>* currentPoint = currentRoute->value.first;
        while (currentPoint != nullptr) {
            File << "Punto: " << currentPoint->value.getX() << ", " << currentPoint->value.getY() << " - Nombre: " << currentPoint->value.getName() << endl;
            currentPoint = currentPoint->next;
        }
        File << "-----------------------------------" << endl;
        currentRoute = currentRoute->next;
    }

    File.close();
}

void Routes::LoadFromFile() {
    ifstream File("Archivos/Rutas.txt");

    if (!File) {
        cerr << "Error al abrir el archivo para cargar." << endl;
        return;
    }

    string line;
    Node<Route>* lastRouteNode = nullptr;

    while (getline(File, line)) {
        if (line.find("Ruta:") == 0) {
            string routeName = line.substr(6);
            Route newRoute;
            newRoute.name = routeName;

            getline(File, line);
            int r, g, b;

            line.erase(0, 7);
            r = stoi(line.substr(0, line.find(" ")));
            line.erase(0, line.find(" ") + 1);
            g = stoi(line.substr(0, line.find(" ")));
            line.erase(0, line.find(" ") + 1);
            b = stoi(line.substr(0, line.find(" ")));
            line.erase(0, line.find(" ") + 1);

            newRoute.color = Color(r, g, b);
            addRoute(newRoute);
            lastRouteNode = last;
        }
        else if (line.find("Punto:") == 0 && lastRouteNode != nullptr) {
            
            line.erase(0,7);

            float x = stof(line.substr(0, line.find(",")));
            line.erase(0, line.find(",") + 2);
            float y = stof(line.substr(0, line.find(" ")));

            line.erase(0, line.find(":") + 2);
            string pointName = line.substr();
            
            Coordinate newCoord(x, y);
            newCoord.setName(pointName);
            lastRouteNode->value.insertLast(newCoord);
        }

    }

    File.close();
}
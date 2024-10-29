#include "App.h"

App::App()
{
    MenuTexture.loadFromFile("Imagenes/Menu.png");
    Menu.setTexture(MenuTexture);
    CreateMenuButtons();
    Window.create(VideoMode(1380, 720), "Rutas Turísticas");
    MapTexture.loadFromFile("Imagenes/MapaN.png");
    Map.setTexture(MapTexture);
    CreateMapButtons();
    CreatePallette();

}

void App::Start()
{
    DrawMenu();
    DrawMap();
}

void App::DrawMenu()
{
    Window.setFramerateLimit(60);
    while (Window.isOpen())
    {
        Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                Window.close();

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    Vector2f mousePos = Window.mapPixelToCoords(Mouse::getPosition(Window));

                    if (StartButton.getGlobalBounds().contains(mousePos)) {
                       
                        return;
                    }
                    if (ExitButton.getGlobalBounds().contains(mousePos)) {

                        Window.close();
                    }

                    Vector2i pixelPos = Mouse::getPosition(Window);
                    Vector2f worldPos = Window.mapPixelToCoords(pixelPos);
                    cout << "Coordenadas del clic: X = " << worldPos.x << ", Y = " << worldPos.y << std::endl;
                }
            }
        }

        Window.clear(Color::Black);
        Window.draw(Menu);
        Window.draw(StartButton);
        Window.draw(ExitButton);
        Window.display();
    }
}

void App::DrawMap()
{
    Window.setFramerateLimit(60);
    while (Window.isOpen())
    {
        Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                Window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2f mousePos = Window.mapPixelToCoords(Mouse::getPosition(Window));
                    HandleMapButtons(mousePos);
                    if (activeRoute != nullptr) { // Verifica si hay una ruta activa
                        if (canCreate) {
                            CreatePoint(mousePos); // Crear un punto si se puede
                        }
                        else {
                            activeRoute->value.DeleteAPoint(mousePos); // Intentar eliminar un punto
                        }
                    }
                    Vector2i pixelPos = Mouse::getPosition(Window);
                    cout << "Coordenadas del clic: X = " << pixelPos.x << ", Y = " << pixelPos.y << endl;   
                }
            }
        }
        Window.clear();
        Window.draw(Map);
        DrawMapButtons(Window);
        ListOfRoutes.Draw(Window);
        Window.display();
    }

}

void App::CreateMenuButtons()
{
    float PositionX = 72;
    float PositionY = 391;
    StartButton.setSize(Vector2f(278.8, 107.9));
    StartButton.setFillColor(Color::Transparent);
    StartButton.setPosition(PositionX, PositionY);

    float PositionY2 = 540.1;
    ExitButton.setSize(Vector2f(278.8, 107.9));
    ExitButton.setFillColor(Color::Transparent);
    ExitButton.setPosition(PositionX, PositionY2);
}

void App::CreateMapButtons()
{
    SaveTexture.loadFromFile("Imagenes/Botones/Guardar_ruta.png");
    LoadTexture.loadFromFile("Imagenes/Botones/Cargar_ruta.png");
    DeleteTexture.loadFromFile("Imagenes/Botones/Eliminar_ruta.png");
    DeletePointTexture.loadFromFile("Imagenes/Botones/Eliminar_punto.png");
    SelectTexture.loadFromFile("Imagenes/Botones/Cambiar_ruta.png");
    GoBackTexture.loadFromFile("Imagenes/Botones/Regresar.png");
    CreateTexture.loadFromFile("Imagenes/Botones/Crear_nueva_ruta.png");
    SaveSprite.setTexture(SaveTexture);
    LoadSprite.setTexture(LoadTexture);
    DeleteSprite.setTexture(DeleteTexture);
    DeletePointSprite.setTexture(DeletePointTexture);
    SelectSprite.setTexture(SelectTexture);
    GoBackSprite.setTexture(GoBackTexture);
    CreateSprite.setTexture(CreateTexture);


}

void App::CreatePallette()
{
    ColorOrangeT.loadFromFile("Imagenes/Botones/Color_naranja.png");
    ColorPurpleT.loadFromFile("Imagenes/Botones/Color_morado.png");
    ColorBlueT.loadFromFile("Imagenes/Botones/Color_azul.png");
    ColorRedT.loadFromFile("Imagenes/Botones/Color_rojo.png");
    ColorYellowT.loadFromFile("Imagenes/Botones/Color_amarillo.png");
    ColorGreenT.loadFromFile("Imagenes/Botones/Color_verde.png");
    ColorOrangeS.setTexture(ColorOrangeT);
    ColorPurpleS.setTexture(ColorPurpleT);
    ColorBlueS.setTexture(ColorBlueT);
    ColorRedS.setTexture(ColorRedT);
    ColorYellowS.setTexture(ColorYellowT);
    ColorGreenS.setTexture(ColorGreenT);
}
void App::DrawMapButtons(RenderWindow& window)
{
    CreateSprite.setPosition(6.2, 14.9);
    CreateSprite.setScale(0.68, 0.68);
    window.draw(CreateSprite);
    SaveSprite.setPosition(107.7, 72);
    SaveSprite.setScale(0.68, 0.68);
    window.draw(SaveSprite);
    LoadSprite.setPosition(6.2, 128.5);
    LoadSprite.setScale(0.68, 0.68);
    window.draw(LoadSprite);
    SelectSprite.setPosition(107.7, 185.6);
    SelectSprite.setScale(0.68, 0.68);
    window.draw(SelectSprite);
    DeleteSprite.setPosition(6.2, 241.6);
    DeleteSprite.setScale(0.68, 0.68);
    window.draw(DeleteSprite);
    DeletePointSprite.setPosition(107.7, 298.7);
    DeletePointSprite.setScale(0.68, 0.68);
    window.draw(DeletePointSprite);
    GoBackSprite.setPosition(6.2, 354.7);
    GoBackSprite.setScale(0.68, 0.68);
    window.draw(GoBackSprite);
    ColorRedS.setPosition(42.1, 422.5);
    window.draw(ColorRedS);
    ColorOrangeS.setPosition(140.7, 422.5);
    window.draw(ColorOrangeS);
    ColorYellowS.setPosition(42.1, 517.6);
    window.draw(ColorYellowS);
    ColorGreenS.setPosition(140.7, 517.6);
    window.draw(ColorGreenS);
    ColorBlueS.setPosition(42.1, 612.7);
    window.draw(ColorBlueS);
    ColorPurpleS.setPosition(140.7, 612.7);
    window.draw(ColorPurpleS);

}

void App::CreatePoint(Vector2f mousePos)
{
    // Verifica que la posición del mouse esté dentro del área del mapa
    if (mousePos.x >= 280 && mousePos.x <= 1380 && mousePos.y >= 1 && mousePos.y <= 720) {
        // Asegúrate de que haya una ruta activa
        if (activeRoute == nullptr) {
            printf("Error: No hay una ruta activa para agregar el punto.\n");
            return;
        }

        // Crear una nueva coordenada y agregarla a la ruta activa
        Coordinate newCoord(mousePos.x, mousePos.y);
        activeRoute->value.insertLast(newCoord);

        printf("Coordenada agregada a la ruta activa: (%.2f, %.2f)\n", mousePos.x, mousePos.y);
    }
}


void App::HandleMapButtons(Vector2f mousePos)
{
    if (CreateSprite.getGlobalBounds().contains(mousePos)) {
        canCreate = true;
        printf("Botón de creación de ruta clicado\n");
        if (canCreate) {
            if (activeRoute != nullptr) {
                printf("Ruta anterior finalizada y guardada.\n");
            }

            Route newRoute;

            ListOfRoutes.addRoute(newRoute);

            activeRoute = ListOfRoutes.first;
            while (activeRoute->next != nullptr) {
                activeRoute = activeRoute->next;
            }
            printf("Nueva ruta creada y lista para agregar puntos.\n");
        }
    }
    else if (SaveSprite.getGlobalBounds().contains(mousePos)) {
        cout << "Guardar Rutas" << endl;
    }
    else if (LoadSprite.getGlobalBounds().contains(mousePos)) {
        cout << "Cargar rutas" << endl;
    }
    else if (SelectSprite.getGlobalBounds().contains(mousePos)) {
        cout << "Cambiar ruta" << endl;
        if (activeRoute != nullptr) {
            if (activeRoute->next != nullptr)
                activeRoute = activeRoute->next;
            else
                activeRoute = ListOfRoutes.first;
        }
    }
    else if (DeleteSprite.getGlobalBounds().contains(mousePos)) {
        
        if (activeRoute != nullptr) {
            Node<Route>* routeToDelete = activeRoute;
            if (activeRoute->next != nullptr)
                activeRoute = activeRoute->next;
            else
                activeRoute = ListOfRoutes.first;
            ListOfRoutes.DeleteCurrentRoute(routeToDelete);
            cout << "Eliminar ruta" << endl;
            if (ListOfRoutes.size == 0) {
                activeRoute = nullptr;
            }
        }
    }
    else if (DeletePointSprite.getGlobalBounds().contains(mousePos)) {
        if (canCreate == true) {
            canCreate = false;
        }
        else {
            canCreate = true;
        }
        cout << "Eliminar punto" << endl;

    }
    else if (GoBackSprite.getGlobalBounds().contains(mousePos)) {
        cout << "Regresar" << endl;
        Start();
    }
    else if (ColorRedS.getGlobalBounds().contains(mousePos)) {
        cout << "Red" << endl;
        if (activeRoute != nullptr) {
            activeRoute->value.color = Color::Red;
        }
    }
    else if (ColorOrangeS.getGlobalBounds().contains(mousePos)) {
        cout << "Orange" << endl;
        if (activeRoute != nullptr) {
            activeRoute->value.color = Color(255, 138, 0);
        }
    }
    else if (ColorYellowS.getGlobalBounds().contains(mousePos)) {
        cout << "Yellow" << endl;
        if (activeRoute != nullptr) {
            activeRoute->value.color = Color::Yellow;
        }
    }
    else if (ColorGreenS.getGlobalBounds().contains(mousePos)) {
        cout << "Green" << endl;
        if (activeRoute != nullptr) {
            activeRoute->value.color = Color::Green;
        }
    }
    else if (ColorBlueS.getGlobalBounds().contains(mousePos)) {
        cout << "Blue" << endl;
        if (activeRoute != nullptr) {
            activeRoute->value.color = Color::Blue;
        }
    }
    else if (ColorPurpleS.getGlobalBounds().contains(mousePos)) {
        cout << "Purple" << endl;
        if (activeRoute != nullptr) {
            activeRoute->value.color = Color(170, 142, 214);
        }
    }
}

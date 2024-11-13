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
    ListOfRoutes.LoadFromFile();
    activeRoute = ListOfRoutes.first;
    if (ListOfRoutes.first != nullptr) {
        canCreate = true;
    }
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
                    HandleMapButtons(Window, mousePos);
                    if (activeRoute != nullptr) {
                        if (canCreate) {
                            CreatePoint(mousePos);
                        }
                        else {
                            activeRoute->value.DeleteAPoint(mousePos);
                        }
                    }  
                }
            }
        }
        Window.clear();
        Window.draw(Map);
        DrawMapButtons(Window);
        ListOfRoutes.DrawRoutes(Window, activeRoute);
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
    ColorPinkT.loadFromFile("Imagenes/Botones/Color_rosado.png");
    ColorWhiteT.loadFromFile("Imagenes/Botones/Color_blanco.png");
    ColorRedT.loadFromFile("Imagenes/Botones/Color_rojo.png");
    ColorYellowT.loadFromFile("Imagenes/Botones/Color_amarillo.png");
    ColorBlackT.loadFromFile("Imagenes/Botones/Color_negro.png");
    ColorOrangeS.setTexture(ColorOrangeT);
    ColorPinkS.setTexture(ColorPinkT);
    ColorWhiteS.setTexture(ColorWhiteT);
    ColorRedS.setTexture(ColorRedT);
    ColorYellowS.setTexture(ColorYellowT);
    ColorBlackS.setTexture(ColorBlackT);
}

void App::DrawMapButtons(RenderWindow& window)
{
    CreateSprite.setPosition(20, 20);
    CreateSprite.setScale(0.75, 0.75);
    window.draw(CreateSprite);

    SaveSprite.setPosition(80, 85);
    SaveSprite.setScale(0.75, 0.75);
    window.draw(SaveSprite);

    SelectSprite.setPosition(20, 150);
    SelectSprite.setScale(0.75, 0.75);
    window.draw(SelectSprite);

    DeleteSprite.setPosition(80, 215);
    DeleteSprite.setScale(0.75, 0.75);
    window.draw(DeleteSprite);

    DeletePointSprite.setPosition(20, 280);
    DeletePointSprite.setScale(0.75, 0.75);
    window.draw(DeletePointSprite);

    GoBackSprite.setPosition(80, 345);
    GoBackSprite.setScale(0.75, 0.75);
    window.draw(GoBackSprite);

    ColorRedS.setPosition(42.1, 422.5);
    window.draw(ColorRedS);
    ColorOrangeS.setPosition(140.7, 517.6);
    window.draw(ColorOrangeS);
    ColorYellowS.setPosition(42.1, 517.6);
    window.draw(ColorYellowS);
    ColorBlackS.setPosition(140.7, 612.7);
    window.draw(ColorBlackS);
    ColorWhiteS.setPosition(42.1, 612.7);
    window.draw(ColorWhiteS);
    ColorPinkS.setPosition(140.7, 422.5);
    window.draw(ColorPinkS);

    Switch.setFillColor(Color::Green);
    Switch.setSize(Vector2f(138.8, 5));
    Switch.setPosition(DeletePointSprite.getPosition().x + 20, DeletePointSprite.getPosition().y);
    if (isSwitchVisible) {
        window.draw(Switch);
    }
    
}

void App::CreatePoint(Vector2f mousePos)
{
    if (mousePos.x >= 280 && mousePos.x <= 1380 && mousePos.y >= 1 && mousePos.y <= 720) {
        if (activeRoute == nullptr) {
            printf("Error: No hay una ruta activa para agregar el punto.\n");
            return;
        }
        string pointName = getTextInput(Window, "Ingrese el nombre del nuevo punto: ");
        Coordinate newCoord(mousePos.x, mousePos.y);
        newCoord.setName(pointName);
        activeRoute->value.insertLast(newCoord);
    }
}


void App::HandleMapButtons(RenderWindow &Window, Vector2f mousePos)
{
    if (CreateSprite.getGlobalBounds().contains(mousePos)) {
        canCreate = true;
        if (canCreate) {
            string routeName = getTextInput(Window, "Ingrese el nombre de la nueva ruta: ");
            
            Route newRoute;
            ListOfRoutes.addRoute(newRoute);

            activeRoute = ListOfRoutes.first;
            
            while (activeRoute->next != nullptr) {
                activeRoute = activeRoute->next;
            }
            activeRoute->value.name = routeName;
        }
    }
    else if (SaveSprite.getGlobalBounds().contains(mousePos)) {
        ListOfRoutes.SaveToFile();
    }
    else if (LoadSprite.getGlobalBounds().contains(mousePos)) {
        
    }
    else if (SelectSprite.getGlobalBounds().contains(mousePos)) {
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
            if (ListOfRoutes.size == 0) {
                activeRoute = nullptr;
            }
        }
    }
    else if (DeletePointSprite.getGlobalBounds().contains(mousePos)) {
        

        if (canCreate == true) {
            canCreate = false;
            isSwitchVisible = true;
        }
        else {
            canCreate = true;
            isSwitchVisible = false;
        }
       
    }
    else if (GoBackSprite.getGlobalBounds().contains(mousePos)) {
        DrawMenu();
    }
    else if (ColorRedS.getGlobalBounds().contains(mousePos)) {
        if (activeRoute != nullptr) {
            activeRoute->value.color = Color::Red;
        }
    }
    else if (ColorOrangeS.getGlobalBounds().contains(mousePos)) {
        if (activeRoute != nullptr) {
            activeRoute->value.color = Color(255, 107, 0);
        }
    }
    else if (ColorYellowS.getGlobalBounds().contains(mousePos)) {
        if (activeRoute != nullptr) {
            activeRoute->value.color = Color::Yellow;
        }
    }
    else if (ColorBlackS.getGlobalBounds().contains(mousePos)) {
        if (activeRoute != nullptr) {
            activeRoute->value.color = Color::Black;
        }
    }
    else if (ColorWhiteS.getGlobalBounds().contains(mousePos)) {
        if (activeRoute != nullptr) {
            activeRoute->value.color = Color::White;
        }
    }
    else if (ColorPinkS.getGlobalBounds().contains(mousePos)) {
        if (activeRoute != nullptr) {
            activeRoute->value.color = Color(255, 0, 214);
        }
    }
}

string App::getTextInput(RenderWindow& window, const string& promptMessage)
{
    Font font;
    font.loadFromFile("Fuentes/Retro_Gaming.ttf");
    RectangleShape dialogBox(Vector2f(400, 150));

    dialogBox.setFillColor(Color(50, 50, 50));
    dialogBox.setOutlineColor(Color::White);
    dialogBox.setOutlineThickness(4);
    dialogBox.setPosition(window.getSize().x / 2 - dialogBox.getSize().x / 2, window.getSize().y / 2 - dialogBox.getSize().y / 2);

    Text promptText(promptMessage, font, 16);
    promptText.setPosition(dialogBox.getPosition().x + 10, dialogBox.getPosition().y + 10);
    promptText.setFillColor(Color::White);

    Text userInputText("", font, 18);
    userInputText.setPosition(dialogBox.getPosition().x + 10, dialogBox.getPosition().y + 60);
    userInputText.setFillColor(sf::Color::White);

    string inputStr;
    bool inputActive = true;
 
    while (inputActive) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return "";
            }
            else if (event.type == Event::TextEntered) {
                if (event.text.unicode == '\b') {
                    if (!inputStr.empty()) {
                        inputStr.pop_back();
                    }
                }
                else if (event.text.unicode == 13) {
                    inputActive = false;
                }
                else if (event.text.unicode < 128) {
                    inputStr += static_cast<char>(event.text.unicode);
                }
                userInputText.setString(inputStr);
            }
        }
        window.draw(dialogBox);
        window.draw(promptText);
        window.draw(userInputText);
        window.display();
    }
    
    return inputStr;
}

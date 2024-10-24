#include "App.h"

App::App()
{
    MenuTexture.loadFromFile("Imagenes/Menu.png");
    Menu.setTexture(MenuTexture);
    CreateMenuButtons();
    Window.create(sf::VideoMode(1380, 720), "Rutas Turísticas");
    MapTexture.loadFromFile("Imagenes/Mapa.png");
    Map.setTexture(MapTexture);
    CreateMapButtons();
    isClicked = false;
    click = 0;
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


                    for (int i = 0; i < 6; i++) {
                        if (MapButtons[i].getGlobalBounds().contains(mousePos)) {
                            HandleButtonClick(i);
                        }
                    }

                    if (isClicked == true) {
                        CreateRute(mousePos);
                    } 
                    Vector2i pixelPos = Mouse::getPosition(Window);
                    Vector2f worldPos = Window.mapPixelToCoords(pixelPos);
                    cout << "Coordenadas del clic: X = " << worldPos.x << ", Y = " << worldPos.y << std::endl;

                   
                    
                }
                
            }
        }

        Window.clear();
        Window.draw(Map);
        for (int i = 0; i < 6; i++) {
            Window.draw(MapButtons[i]);
        }
        Rute.DrawList(Window);
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
    float PossitionX = 17.5;
    float PossitionY = 24.1;
    for (int i = 0; i < 6; i++) {
        MapButtons[i].setSize(Vector2f(239.9, 82.2));
        MapButtons[i].setPosition(PossitionX, PossitionY);
        MapButtons[i].setFillColor(Color::Transparent);
        PossitionY += 119.2;
    }
}


void App::HandleButtonClick(int buttonNumber) {

    switch (buttonNumber) {
    case 0:
        printf("Crear una nueva ruta clicado\n");
        if (click % 2 == 0) {
            isClicked = true;
            click = click + 1;
        }
        else {
            isClicked = false;
            click = click + 1;
        }
        break;

    case 1:
        printf("Seleccionar color clicado\n");
        break;

    case 2:
        printf("Guardar ruta clicado\n");
        break;

    case 3:
        printf("Cargar rutas clicado\n");
        break;

    case 4:
        printf("Editar rutas clicado\n");
        break;

    case 5:
        Start();
        break;

    default:
        break;
    }
}

void App::CreateRute(Vector2f mousePos)
{
    if (mousePos.x >= 280 && mousePos.x <= 1380 && mousePos.y >= 1 && mousePos.y <= 720) {
        Coordinate newCoord(mousePos.x, mousePos.y);
        Rute.insertLast(newCoord);
    }
}

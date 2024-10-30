#pragma once
#include <iostream>
#include "Routes.h"
using namespace std;

class App
{
private:
	RenderWindow MainMenu;
	Texture MenuTexture;
	Sprite Menu;
	RectangleShape StartButton;
	RectangleShape ExitButton;
	RenderWindow Window;
	Texture MapTexture;
	Sprite Map;
	Routes ListOfRoutes;
	Texture SaveTexture, LoadTexture, DeleteTexture, DeletePointTexture, SelectTexture, GoBackTexture, CreateTexture;
	Sprite SaveSprite, LoadSprite, DeleteSprite, DeletePointSprite, SelectSprite, GoBackSprite, CreateSprite;
	Texture ColorOrangeT, ColorPurpleT, ColorBlueT, ColorRedT, ColorYellowT, ColorGreenT;
	Sprite ColorOrangeS, ColorPurpleS, ColorBlueS, ColorRedS, ColorYellowS, ColorGreenS;
	bool canCreate = false;
	bool isCreatingRoute = false;
	Node<Route>* activeRoute = nullptr;
	
public:


	App();
	void Start();
	void DrawMenu();
	void DrawMap();
	void CreateMenuButtons();
	void CreateMapButtons();
	void CreatePallette();
	void CreatePoint(Vector2f mousePos);
	void DrawMapButtons(RenderWindow &window);
	void HandleMapButtons(RenderWindow& Window, Vector2f mousePos);
	string getTextInput(RenderWindow& window, const string& promptMessage);
};


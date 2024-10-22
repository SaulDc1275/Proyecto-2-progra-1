#pragma once
#include <iostream>
#include "List.h"
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
	RectangleShape MapButtons[6];
	List<CircleShape> Rute;

public:


	App();
	void Start();
	void DrawMenu();
	void DrawMap();
	void CreateMenuButtons();
	void CreateMapButtons();
	void HandleButtonClick(int buttonIndex);
};


#pragma once
#include <iostream>
#include "Rute.h"
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
	Rute Rute;
	Texture SaveTexture, LoadTexture, DeleteTexture, DeletePointTexture, SelectRoute;
	bool isClicked;
	int click;
public:


	App();
	void Start();
	void DrawMenu();
	void DrawMap();
	void CreateMenuButtons();
	void CreateMapButtons();
	void HandleButtonClick(int buttonIndex);
	void CreateRute(Vector2f mousePos);
};


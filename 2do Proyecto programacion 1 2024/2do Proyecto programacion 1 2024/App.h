#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
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

public:


	App();
	void Start();
	void DrawMenu();
	void DrawMap();
	void CreateMenuButtons();
	void CreateMapButtons();
	void HandleButtonClick(int buttonIndex);
};


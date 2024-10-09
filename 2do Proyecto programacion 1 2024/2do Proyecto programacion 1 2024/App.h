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
	Text StartButtonText;
	RenderWindow Window;
	Texture MapTexture;
	Sprite Map;
	RectangleShape buttons[6];
	Text buttonTexts[6];
	Font font;


public:

	App();
	void Start();
	void DrawMenu();
	void DrawMap();
	void CreateMenuButton();
	void CreateMapButtons();
	void HandleButtonClick(int buttonIndex);
};


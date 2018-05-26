#pragma once
#include "Menu.h"
#include "Game.h"

using namespace sf;

class MenuOption :public sf::Drawable 
{
public:
	MenuOption() = default;
	~MenuOption() = default;
	friend bool detect(MenuOption* menuOption);
	bool detection{ false };
protected:
	int width{ 200 };
	int height{ 50 };
	Color background{ 16, 168, 124 };
	Color outlineColor{ 2, 22, 16 };
	int outlineThickness{ 1 };
	string name;
	int xPosition{ 384 }; //center, witch origin for x and y
	int yPosition; 
	Game* game;
	Menu* menu;
	RenderWindow* window;
	virtual void action() = 0;
	void draw(RenderTarget& target, RenderStates state) const override;
};


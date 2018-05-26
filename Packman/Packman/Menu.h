#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

class Menu :public sf::Drawable
{
public:
	Menu(Game* g);
	~Menu() = default;
	Game *game;
	Menu *menu;
	void view(Menu *m);
	bool display{ true };
	Color background{ 16, 74, 168 };
	void draw(RenderTarget& target, RenderStates state) const override;
};


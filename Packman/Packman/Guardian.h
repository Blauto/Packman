#pragma once
#include <SFML\Graphics.hpp>
#include "Map.h"
#include "Game.h"

using namespace sf;

class Guardian
{
public:
	Guardian();
	~Guardian() = default;
	bool checkCollision(Vector2f vector);
	void checkPointCollision(Vector2f topLeft, Vector2f bottomLeft, Vector2f topRight);
protected:
	int width;
	int height;
	Sprite object;
	Map* map;
	Game* game;
	Texture texture;
};


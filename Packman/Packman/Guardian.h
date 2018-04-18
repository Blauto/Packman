#pragma once
#include <SFML\Graphics.hpp>
#include "Map.h"

using namespace sf;

class Guardian
{
public:
	Guardian();
	~Guardian() = default;
	bool checkCollision(Vector2f vector);
protected:
	int width;
	int height;
	Sprite object;
	Map* map;
	Texture texture;
};


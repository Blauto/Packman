#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Map :public sf::Drawable
{
public:
	Map();
	~Map() = default;
private:
	const int mapSizeX{ 32 };
	const int mapSizeY{ 32 };
	const int squerSize{ 25 };
	int wallMap[32][32];
	Texture wallTexture, emptyTexture;
	void draw(RenderTarget& target, RenderStates state) const override;
};


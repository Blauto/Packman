#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Map :public sf::Drawable
{
public:
	Map();
	~Map() = default;
	friend bool check(Map* map, Guardian* object);
private:
	const int mapSizeX{ 64 };
	const int mapSizeY{ 48 };
	const int squerSize{ 12 };
	int wallMap[48][64];
	Texture wallTexture, emptyTexture;
	void draw(RenderTarget& target, RenderStates state) const override;
};
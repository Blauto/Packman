#pragma once
#include <SFML/Graphics.hpp>
#include "Point.h"
#include <list>

using namespace sf;
using namespace std;

class Map :public sf::Drawable
{
public:
	Map();
	~Map() = default;
	friend class Guardian;
private:
	const int mapSizeX{ 64 };
	const int mapSizeY{ 48 };
	const int squerSize{ 12 };
	int wallMap[48][64];
	list<Point> pointList;
	mutable list<Point>::const_iterator it;

	Texture wallTexture, emptyTexture;
	void draw(RenderTarget& target, RenderStates state) const override;
	void addPoint(float x, float y);
	void deletePoint(float x, float y);
};
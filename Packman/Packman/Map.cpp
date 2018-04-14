#include "stdafx.h"
#include "Map.h"

using namespace sf;
using namespace std;

Map::Map()
{
	wallTexture.loadFromFile("wallTexture.png"); 
	emptyTexture.loadFromFile("emptyTexture.png");


	for (int i = 0; i < mapSizeX; i++) {
		for (int j = 0; j < mapSizeY; j++) {
			wallMap[i][j] = 0;
			if(i==5) wallMap[i][j] = 1;
		}
	}
}

void Map::draw(RenderTarget & target, RenderStates state) const
{
	vector <int> coordinate;
	Sprite field;

	for (int i = 0; i < mapSizeX; i++) {
		for (int j = 0; j < mapSizeY; j++) {

			coordinate.clear();
			coordinate.push_back((float)(i*squerSize));
			coordinate.push_back((float)(j*squerSize));
			field.setPosition(sf::Vector2f(coordinate[1], coordinate[0]));
			if (wallMap[i][j] == 1) {

				field.setTexture(wallTexture);
			} else {

				field.setTexture(emptyTexture);
			}
			target.draw(field, state);
		}
	}
}


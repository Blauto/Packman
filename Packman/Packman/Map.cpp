#include "stdafx.h"
#include "Map.h"
#include <fstream>
#include <math.h>

using namespace sf;
using namespace std;

Map::Map()
{
	wallTexture.loadFromFile("wallTexture.png"); 
	emptyTexture.loadFromFile("emptyTexture.png");

	fstream map, pointMap;
	map.open("map.txt", ios::in);
	pointMap.open("pointMap.txt", ios::in);

	if (map.good() == false || pointMap.good() == false) { //oznacza ze plik nie istnieje 

		cout << "W katalogu z programem musi znalezæ siê plik base.blaut" << endl;
		for (int i = 0; i < mapSizeY; i++) {
			for (int j = 0; j < mapSizeX; j++) {
				wallMap[i][j] = 1;
			}
		}
	} else {

		string mapLine;
		string mapPoint;
		for (int i = 0; i < mapSizeY; i++) {
			getline(map, mapLine);
			getline(pointMap, mapPoint);
			for (int j = 0; j < mapSizeX; j++) {
				wallMap[i][j] = mapLine[j] - 48;
				if ((mapPoint[j] - 48) == 1) {
					addPoint(squerSize*j, squerSize*i);
				}
			}
		}
		map.close();
		pointMap.close();
	}
}

void Map::draw(RenderTarget & target, RenderStates state) const
{
	vector <int> coordinate;
	Sprite field;

	for (int i = 0; i < mapSizeY; i++) { //rysowanie mapy
		for (int j = 0; j < mapSizeX; j++) {

			coordinate.clear();
			coordinate.push_back((float)i*squerSize);
			coordinate.push_back((float)j*squerSize);
			field.setPosition(sf::Vector2f(coordinate[1], coordinate[0]));
			if (wallMap[i][j] == 1) {

				field.setTexture(wallTexture);
			} else {

				field.setTexture(emptyTexture);
			}
			target.draw(field, state);
		}
	}

	for (it = pointList.begin(); it != pointList.end(); ++it) //rysowanie punktów
	{
		target.draw(it->object, state);
	}
}

void Map::addPoint(float x, float y)
{
	Point newPoint(x, y);

	pointList.push_back(newPoint);
}

void Map::deletePoint(float x, float y)
{
}

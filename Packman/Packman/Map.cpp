#include "stdafx.h"
#include "Map.h"
#include <fstream>
#include <iostream>

using namespace sf;
using namespace std;

Map::Map()
{
	wallTexture.loadFromFile("wallTexture.png"); 
	emptyTexture.loadFromFile("emptyTexture.png");

	fstream file;
	file.open("map.txt", ios::in);

	if (file.good() == false) { //oznacza ze plik nie istnieje 

		cout << "W katalogu z programem musi znalezæ siê plik base.blaut" << endl;
		for (int i = 0; i < mapSizeY; i++) {
			for (int j = 0; j < mapSizeX; j++) {
				wallMap[i][j] = 1;
			}
		}
	} else {

		string line;
		int numOfLine = 1;
		for (int i = 0; i < mapSizeY; i++) {
			getline(file, line);
			for (int j = 0; j < mapSizeX; j++) {
				wallMap[i][j] = line[j] - 48;
			}
		}
		file.close();
	}
	
}

void Map::draw(RenderTarget & target, RenderStates state) const
{
	vector <int> coordinate;
	Sprite field;

	for (int i = 0; i < mapSizeY; i++) {
		for (int j = 0; j < mapSizeX; j++) {

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


#include "stdafx.h"
#include "Guardian.h"
#include <math.h>

using namespace sf;
using namespace std;

Guardian::Guardian()
{
}

bool Guardian::checkCollision(Vector2f vector)
{
	object.move(vector);

	Vector2f top = object.getPosition();
	Vector2f bottom = top;
	Vector2f left = top;
	Vector2f right = top;

	Vector2f topLeft = top;
	Vector2f bottomLeft = top;
	Vector2f topRight = top;
	Vector2f bottomRight = top;


	top.y -= width / 2;
	bottom.y += width / 2;
	left.x -= width / 2;
	right.x += width / 2;

	topLeft.y -= width / 2;
	topLeft.x -= width / 2;

	bottomRight.y += width / 2;
	bottomRight.x += width / 2;

	bottomLeft.x -= width / 2;
	bottomLeft.y += width / 2;

	topRight.x += width / 2;
	topRight.y -= width / 2;

	checkPointCollision(topLeft, bottomLeft, topRight);

	//cout << "x:" << topLeft.x << "     y:" << topLeft.y << endl;

	bool permision = true;
	if (map->wallMap[(int)floor(top.y/map->squerSize)][(int)floor(top.x / map->squerSize)] == 1)
		permision = false;
	else if (map->wallMap[(int)floor(bottom.y / map->squerSize)][(int)floor(bottom.x / map->squerSize)] == 1)
		permision = false;
	else if (map->wallMap[(int)floor(left.y / map->squerSize)][(int)floor(left.x / map->squerSize)] == 1)
		permision = false;
	else if (map->wallMap[(int)floor(right.y / map->squerSize)][(int)floor(right.x / map->squerSize)] == 1)
		permision = false;

	else if (map->wallMap[(int)floor(topLeft.y / map->squerSize)][(int)floor(topLeft.x / map->squerSize)] == 1)
		permision = false;
	else if (map->wallMap[(int)floor(bottomRight.y / map->squerSize)][(int)floor(bottomRight.x / map->squerSize)] == 1)
		permision = false;
	else if (map->wallMap[(int)floor(bottomLeft.y / map->squerSize)][(int)floor(bottomLeft.x / map->squerSize)] == 1)
		permision = false;
	else if (map->wallMap[(int)floor(topRight.y / map->squerSize)][(int)floor(topRight.x / map->squerSize)] == 1)
		permision = false;

	object.move(-vector);
	return permision;
}

void Guardian::checkPointCollision(Vector2f topLeft, Vector2f bottomLeft, Vector2f topRight)
{
	Vector2f pointPosition;
	list<Point>::const_iterator it;

	for (it = map->pointList.begin(); it != map->pointList.end(); ++it) //rysowanie punktów
	{
		pointPosition = it->object.getPosition();
		if (pointPosition.x > topLeft.x
			&& pointPosition.x < topRight.x
			&& pointPosition.y > topLeft.y
			&& pointPosition.y < bottomLeft.y) {

			map->pointList.erase(it);
			game->addPlayerPoint();
			break;
		}
	}
}



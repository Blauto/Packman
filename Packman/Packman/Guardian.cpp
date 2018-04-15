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
	top.y += width / 2;
	bottom.y -= width / 2;
	left.x += width / 2;
	right.x -= width / 2;




	cout << "x:" << top.x << "     y:" << top.y << endl;

	bool permision = true;
	if (map->wallMap[(int)floor(top.y/map->squerSize)][(int)floor(top.x / map->squerSize)] == 1)
		permision = false;
	else if (map->wallMap[(int)floor(bottom.y / map->squerSize)][(int)floor(bottom.x / map->squerSize)] == 1)
		permision = false;
	else if (map->wallMap[(int)floor(left.y / map->squerSize)][(int)floor(left.x / map->squerSize)] == 1)
		permision = false;
	else if (map->wallMap[(int)floor(right.y / map->squerSize)][(int)floor(right.x / map->squerSize)] == 1)
		permision = false;

	if(!permision) 
		object.move(-vector);
	return permision;
}



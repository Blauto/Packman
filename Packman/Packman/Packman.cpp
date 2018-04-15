#include "stdafx.h"
#include "Packman.h"

using namespace sf;
using namespace std;

Packman::Packman(float x, float y)
{

	texture.loadFromFile("C:/Users/bogusia/Source/Repos/Packman/Packman/Packman/packman.png");
	object.setTexture(texture);

	Vector2f textureSize{ texture.getSize() };
	Vector2f sizeVector{(float)(width), (float)height };
	Vector2f scaleVector( sizeVector.x / textureSize.x, sizeVector.y / textureSize.y );

	object.setScale(scaleVector);
	object.setPosition(x, y);
	object.setOrigin(width,height);
}

void Packman::update()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {

		object.setRotation(180);
		object.move(velocityVectorLeft);
	} else if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {

		object.setRotation(0);
		object.move(velocityVectorRight);
	} else if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {

		object.setRotation(270);
		object.move(velocityVectorTop);
	} else if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {

		object.setRotation(90);
		object.move(velocityVectorBottom);
	}
}

void Packman::getObject()
{
}

void Packman::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->object, state);
}



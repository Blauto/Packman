#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Guardian
{
public:
	Guardian();
	~Guardian() = default;
private:
	int width;
	int height;
	Sprite fff;
	virtual void getObject() = 0;
};


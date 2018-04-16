#pragma once
#include <SFML/Graphics.hpp>
#include "Guardian.h"
#include "Map.h"

using namespace sf;

class Packman :public sf::Drawable, protected virtual Guardian
{
public:
	Packman(float x, float y, Map *map);
	Packman() = delete;
	~Packman() = default;
	void update();
private:
	const float velocity{ 3.5f };
	Vector2f velocityVectorLeft{ -velocity , 0 };
	Vector2f velocityVectorRight{ velocity , 0 };
	Vector2f velocityVectorTop{ 0 , -velocity };
	Vector2f velocityVectorBottom{ 0 , velocity };
	void draw(RenderTarget& target, RenderStates state) const override;
};


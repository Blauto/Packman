#pragma once
#include <SFML/Graphics.hpp>
#include "Guardian.h"
#include "Map.h"

using namespace sf;

class Packman :public sf::Drawable, public virtual Guardian
{
public:
	Packman(float x, float y);
	Packman() = delete;
	~Packman() = default;
	const int width{ 24 };
	const int height{ 24 };
	void update();
	void getObject();
private:
	Sprite object;
	Texture texture;
	const float velocity{ 16.0f };
	Vector2f velocityVectorLeft{ -velocity , 0 };
	Vector2f velocityVectorRight{ velocity , 0 };
	Vector2f velocityVectorTop{ 0 , -velocity };
	Vector2f velocityVectorBottom{ 0 , velocity };
	void draw(RenderTarget& target, RenderStates state) const override;
};


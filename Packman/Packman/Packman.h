#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Packman :public sf::Drawable
{
public:
	Packman(float x, float y);
	Packman() = delete;
	~Packman() = default;
	void update();
private:
	Sprite player;
	Texture texture;
	const int width{ 50 };
	const int height{ 50 };
	float positionX;
	float positionY;
	const float velocity{ 6.0f };
	Vector2f velocityVectorLeft{ -velocity , 0 };
	Vector2f velocityVectorRight{ velocity , 0 };
	Vector2f velocityVectorTop{ 0 , -velocity };
	Vector2f velocityVectorBottom{ 0 , velocity };
	void draw(RenderTarget& target, RenderStates state) const override;
};


#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Point :public sf::Drawable
{
public:
	Point(float x, float y);
	~Point() = default;
	friend class Map;
private:
	CircleShape object;
	float radius{ 6 };
	Color color{ 230, 228, 228 };
	void draw(RenderTarget& target, RenderStates state) const override;
};

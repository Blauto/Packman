#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game() = default;
	void run(Game *game);
	void refreshPlayerPoint(sf::Text *text);
	void setPlayerPointText(sf::Text *text, sf::Font *font);
	int playerPoints{ 0 };
	void addPlayerPoint();
};

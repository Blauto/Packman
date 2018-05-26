#include "stdafx.h"
#include <sstream>

using namespace sf;
using namespace std;

Game::Game()
{
}

void Game::run(Game *game)
{
	RenderWindow window{ VideoMode{ 768, 576 }, "Packman++" };
	window.setFramerateLimit(60);

	Event event;
	Map map;
	Packman player(24, 24, &map, game);
	Text points;
	Font font;
	setPlayerPointText(&points, &font);
	
	while (true)
	{
		refreshPlayerPoint(&points);

		window.clear(Color::Black);
		window.pollEvent(event);

		if (event.type == Event::Closed) {
			window.close();
			break;
		}

		player.update();

		window.draw(map);
		window.draw(player);
		window.draw(points);
		window.display();
	}
}

void Game::refreshPlayerPoint(Text * text)
{
	ostringstream ss;
	ss << playerPoints;
	string playerPo = ss.str();

	text->setString(playerPo);
}

void Game::setPlayerPointText(sf::Text * text, sf::Font *font)
{
	if (!font->loadFromFile("ObelixPro.ttf"))
		cout << "Can't find the font file." << endl;
	text->setFont(*font);
	text->setCharacterSize(30);
	text->setStyle(sf::Text::Bold);
	text->setPosition(sf::Vector2f(690, 135));
	text->setOutlineColor(sf::Color::Black);
	text->setOutlineThickness( 1 );
}

void Game::addPlayerPoint()
{
	playerPoints++;
}

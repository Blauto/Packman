#include "stdafx.h"

using namespace sf;
using namespace std;

Game::Game()
{
}

void Game::run()
{
	RenderWindow window{ VideoMode{ 800, 600 }, "Packman++" };
	window.setFramerateLimit(60);

	Event event;
	Packman player(50, 50);
	Map map;
	while (true)
	{
		window.clear(Color::Black);
		window.pollEvent(event);

		if (event.type == Event::Closed) {
			window.close();
			break;
		}

		player.update();

		window.draw(map);
		window.draw(player);
		window.display();
	}
}


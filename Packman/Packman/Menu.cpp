#include "stdafx.h"
#include "Menu.h"

using namespace sf;


Menu::Menu(Game * g)
{
	game = g;
}

bool exitMessegBox();

void Menu::view(Menu *m)
{
	menu = m;

	RenderWindow window{ VideoMode{ 768, 576 }, "Packman++" };
	window.setFramerateLimit(60);

	Event event;
	OptionPlay play(menu, game, &window);
	OptionExit exit(menu, game, &window);

	while (true) {
		window.clear(background);
		window.pollEvent(event);

		if (event.type == Event::Closed) {
			if (exitMessegBox()) {
				display = false;
				break;
			}
		}

		if (detect(&play))
			break;
		if (detect(&exit) && exit.detection == true)
			break;

		window.draw(play);
		window.draw(exit);
		window.display();
	}

	window.close();

	if(play.detection)
	    game->run(game);
	if(exit.detection)
		display = false;
}

void Menu::draw(RenderTarget & target, RenderStates state) const
{
}


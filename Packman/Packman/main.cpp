// Packman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace sf;
using namespace std;

int main()
{
	
	Game game;
	Menu menu(&game);

	while (menu.display) {

		menu.view(&menu);
	}

	return 0;
}


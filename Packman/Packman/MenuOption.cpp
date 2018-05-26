#include "stdafx.h"
#include "MenuOption.h"

using namespace sf;

void MenuOption::draw(RenderTarget & target, RenderStates state) const
{
	int xWitchOrigin = xPosition - width / 2;
	int yWitchOrigin = yPosition - height / 2;
	RectangleShape *rectangle = new RectangleShape;
	Text *text = new Text;
	Font *font = new Font;
	font->loadFromFile("ObelixPro.ttf");

	text->setString(name);
	text->setCharacterSize(20);
	text->setFont(*font);
	float textWidth = text->getLocalBounds().width;
	text->setPosition(xWitchOrigin + width/2 - textWidth/2, yWitchOrigin + height/3);


	rectangle->setSize(sf::Vector2f(width, height));
	rectangle->setOutlineColor(sf::Color::Red);
	rectangle->setOutlineThickness(outlineThickness);
	rectangle->setFillColor(background);
	rectangle->setPosition(xWitchOrigin, yWitchOrigin);

	target.draw(*rectangle, state);
	target.draw(*text, state);

	delete rectangle;
	delete text;
	delete font;
}

bool detect(MenuOption* menuOption)
{
	int xWitchOrigin = menuOption->xPosition - menuOption->width / 2;
	int yWitchOrigin = menuOption->yPosition - menuOption->height / 2;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		sf::Vector2i mousePos = sf::Mouse::getPosition(*menuOption->window);

		if (xWitchOrigin < mousePos.x
			&& xWitchOrigin + menuOption->width > mousePos.x
			&& yWitchOrigin < mousePos.y
			&& yWitchOrigin + menuOption->height > mousePos.y
			) {

			menuOption->action();
			return true;
		}
	}
	return false;
}

bool exitMessegBox()
{
	RenderWindow window{ VideoMode{ 360, 150 }, "Exit" };
	window.setFramerateLimit(60);

	int optionWidth = 110;
	int optionHeight = 27;
	RectangleShape yes(sf::Vector2f(optionWidth, optionHeight)), no(sf::Vector2f(optionWidth, optionHeight));
	Color fillColorButton(209, 209, 209);
	Color fillColorBackgrount(227, 229, 229);
	Color outlineColor(40, 40, 40);

	yes.setFillColor(fillColorButton);
	no.setFillColor(fillColorButton);

	yes.setOutlineColor(outlineColor);
	no.setOutlineColor(outlineColor);

	yes.setOutlineThickness(1);
	no.setOutlineThickness(1);

	yes.setPosition(sf::Vector2f(35, 100));
	no.setPosition(sf::Vector2f(215, 100));

	Font font;
	font.loadFromFile("Roboto-Medium.ttf");

	Text text;
	text.setFont(font);
	text.setCharacterSize(17);
	text.setFillColor(outlineColor);

	window.clear(fillColorBackgrount);

	window.draw(yes);
	window.draw(no);

	text.setString("Yes");
	text.setPosition(sf::Vector2f(75, 104));
	window.draw(text);

	text.setString("No");
	text.setPosition(sf::Vector2f(260, 104));
	window.draw(text);

	text.setString("Do you really want to exit?");
	text.setPosition(sf::Vector2f(30, 40));
	window.draw(text);
	while (true) {

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			Vector2i mousePos = sf::Mouse::getPosition(window);

			if (yes.getPosition().x < mousePos.x
				&& yes.getPosition().x + optionWidth > mousePos.x
				&& yes.getPosition().y < mousePos.y
				&& yes.getPosition().y + optionHeight > mousePos.y
				) {
				window.close();
				return true;
			}

			if (no.getPosition().x < mousePos.x
				&& no.getPosition().x + optionWidth > mousePos.x
				&& no.getPosition().y < mousePos.y
				&& no.getPosition().y + optionHeight > mousePos.y
				) {
				window.close();
				return false;
			}
		}
		window.display();
	}
}
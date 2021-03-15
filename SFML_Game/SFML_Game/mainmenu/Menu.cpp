#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("font/TheWildBreathOfZelda-15Lv.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color(250,0,0));
	menu[0].setString("play");
	menu[0].setPosition(sf::Vector2f(1000,350));
	menu[0].setCharacterSize(170);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color(255,255,255));
	menu[1].setString("options");
	menu[1].setPosition(sf::Vector2f(1000, 350+200));
	menu[1].setCharacterSize(150);

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color(255, 255, 255));
	menu[2].setString("quit");
	menu[2].setPosition(sf::Vector2f(1000, 350+400));
	menu[2].setCharacterSize(150);

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color(255, 255, 255));
		menu[selectedItemIndex].setCharacterSize(150);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color(255, 0, 0));
		menu[selectedItemIndex].setCharacterSize(170);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color(255, 255, 255));
		menu[selectedItemIndex].setCharacterSize(160);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color(255, 0, 0));
		menu[selectedItemIndex].setCharacterSize(160);
	}
}
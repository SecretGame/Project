#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dungeon Tales", sf::Style::Titlebar | sf::Style::Close);

	Menu menu(window.getSize().x, window.getSize().y);
	sf::Texture bg;
	if(bg.loadFromFile("picture/mainn.png"))
	{}
	sf::Sprite background(bg);
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();
		window.draw(background);
		menu.draw(window);

		window.display();
	}
}
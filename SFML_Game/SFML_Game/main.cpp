#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include <string>
#include <map>

#include "Button.h"
#include "Background.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dungeon Tals!", sf::Style::Fullscreen);

	sf::Texture bgTexture[4];
	bgTexture[0].loadFromFile("./background/bg.png");
	bgTexture[1].loadFromFile("./background/ceiling.png");
	bgTexture[2].loadFromFile("./background/ground.png");
	bgTexture[3].loadFromFile("./background/shadow front.png");

	std::vector<Background> backgrounds;
	backgrounds.push_back(Background(&bgTexture[0], -30.f));
	backgrounds.push_back(Background(&bgTexture[1], -100.f));
	backgrounds.push_back(Background(&bgTexture[2], -300.f));
	backgrounds.push_back(Background(&bgTexture[3], -200.f));

	float deltaTime = 0.0f;
	sf::Clock clock;

	sf::Vector2i mousePosWindow;
	std::map<std::string, Button*> buttons;
	sf::Font font;
	font.loadFromFile("./font/TheWildBreathOfZelda-15Lv.ttf");
	buttons["BTN_1"] = new Button(
		10.f, 970.f, 400.f, 100.f,
		&font, "punch", 30,
		sf::Color(70, 70, 70, 200),
		sf::Color(40, 40, 40, 250),
		sf::Color(20, 20, 20, 50),
		sf::Color(192, 192, 192, 150),
		sf::Color(192, 192, 192, 170),
		sf::Color(192, 192, 192, 200)
	);
	buttons["BTN_2"] = new Button(
		510.f, 970.f, 400.f, 100.f,
		&font, "fireball", 30,
		sf::Color(70, 70, 70, 200),
		sf::Color(40, 40, 40, 250),
		sf::Color(20, 20, 20, 50),
		sf::Color(192, 192, 192, 150),
		sf::Color(192, 192, 192, 170),
		sf::Color(192, 192, 192, 200)
	);
	buttons["BTN_3"] = new Button(
		1010.f, 970.f, 400.f, 100.f,
		&font, "heal", 30,
		sf::Color(70, 70, 70, 200),
		sf::Color(40, 40, 40, 250),
		sf::Color(20, 20, 20, 50),
		sf::Color(192, 192, 192, 150),
		sf::Color(192, 192, 192, 170),
		sf::Color(192, 192, 192, 200)
	);
	buttons["BTN_4"] = new Button(
		1510.f, 970.f, 400.f, 100.f,
		&font, "smoke bomb", 30,
		sf::Color(70, 70, 70, 200),
		sf::Color(40, 40, 40, 250),
		sf::Color(20, 20, 20, 50),
		sf::Color(192, 192, 192, 150),
		sf::Color(192, 192, 192, 170),
		sf::Color(192, 192, 192, 200)
	);

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

		if (deltaTime > 1.0f / 30.0f)
			deltaTime = 1.0f / 30.0f;

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		for (Background& background : backgrounds)
			background.Update(deltaTime);

		window.clear();

		for (Background& background : backgrounds)
			background.Draw(window);

		mousePosWindow = sf::Mouse::getPosition(window);

		buttons["BTN_1"]->update(mousePosWindow);
		buttons["BTN_2"]->update(mousePosWindow);
		buttons["BTN_3"]->update(mousePosWindow);
		buttons["BTN_4"]->update(mousePosWindow);

		buttons["BTN_1"]->render(window);
		buttons["BTN_2"]->render(window);
		buttons["BTN_3"]->render(window);
		buttons["BTN_4"]->render(window);

		window.display();
	}
	return 0;
}
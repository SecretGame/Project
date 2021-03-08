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
	font.loadFromFile("Fonts/Pokemon Solid.ttf");
	buttons["BTN_1"] = new Button(
		10.f, 10.f, 200.f, 50.f,
		&font, "GUI Button 1", 20,
		sf::Color(70, 70, 70, 200),
		sf::Color(40, 40, 40, 250),
		sf::Color(20, 20, 20, 50),
		sf::Color(255, 167, 28, 200),
		sf::Color(255, 167, 28, 255),
		sf::Color(255, 167, 28, 200)
	);
	buttons["BTN_2"] = new Button(
		10.f, 70.f, 200.f, 50.f,
		&font, "GUI Button 2", 20,
		sf::Color(70, 70, 70, 200),
		sf::Color(40, 40, 40, 250),
		sf::Color(20, 20, 20, 50),
		sf::Color(255, 167, 28, 200),
		sf::Color(255, 167, 28, 255),
		sf::Color(255, 167, 28, 200)
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
		buttons["BTN_1"]->render(window);
		buttons["BTN_2"]->render(window);

		window.display();
	}
	return 0;
}
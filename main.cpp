#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include "Background.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Fullscreen);

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

		window.display();
	}
	return 0;
}
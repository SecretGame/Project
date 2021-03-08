#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "sprite & textures");
	sf::Texture tiles;
	tiles.loadFromFile("tiles/3.png");

	sf::Sprite player;

	player.setTexture(tiles);
	player.setTextureRect(sf::IntRect(0, 0, 64, 64));
	player.setColor(sf::Color(80, 146, 222, 255));
	player.setColor(sf::Color::Red);

	sf::Sprite wall;

	wall.setTexture(tiles);
	wall.setTextureRect(sf::IntRect(64, 0, 64, 64));
	wall.setColor(sf::Color(168, 168, 168, 255));
	wall.move(64, 0);

	sf::Event event;

	while (window.isOpen())
	{
		// poll event
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W) player.move(0, -64);
				if (event.key.code == sf::Keyboard::D) player.move(64, 0);
				if (event.key.code == sf::Keyboard::S) player.move(0, 64);
				if (event.key.code == sf::Keyboard::A) player.move(-64, 0);
			}
		}
		window.clear(sf::Color::White);

		window.draw(player);
		window.draw(wall);

		window.display();
	}
	return 0;
}
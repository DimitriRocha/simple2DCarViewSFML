#include <SFML/Graphics.hpp>
#include "Grid.h"
#include <string>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	Grid* grid = new Grid(window.getSize().x, window.getSize().y);
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		if (clock.getElapsedTime().asMilliseconds() > 50)
		{
			if (grid->currentTick <= 0)
			{
				grid->currentTick = 30;
			}
			grid->currentTick -= 1;
			clock.restart();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			grid->playerPos = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			grid->playerPos = 0;
		}

		grid->CreateGrid(&window);
		window.display();
	}

	return 0;
}
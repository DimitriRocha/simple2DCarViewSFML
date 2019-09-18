#pragma once
#include <SFML/Graphics.hpp>
#include <array>

class Grid {
public:
	int currentTick = 30;

private:
	int screenWidth;
	int screenHeight;
	const int gridSize = 30;
	std::array<std::array<int, 30>, 60> grid;

public:
	int playerPos = 0;
	Grid(int screenWidth, int screenHeight);
	void CreateGrid(sf::RenderWindow* windowHandler);

private:
	void initializeGrid();
	void initializeRoad();
	void drawRects(sf::RenderWindow* windowHandler);
	void drawSprites(sf::RenderWindow* windowHandler);
	void drawPlayer(sf::RenderWindow* windowHandler);
};
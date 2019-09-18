#include "Grid.h";

Grid::Grid(int screenWidth, int screenHeight){
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->currentTick = 0;

	this->initializeGrid();
	this->initializeRoad();
}

void Grid::CreateGrid(sf::RenderWindow* windowHandler){
	this->drawRects(windowHandler);
	this->drawSprites(windowHandler);
	this->drawPlayer(windowHandler);
}

void Grid::initializeGrid(){
	for (size_t i = 0; i < this->grid.size(); i++){
		for (size_t j = 0; j < this->grid[i].size(); j++){
			this->grid[i][j] = 0;
		}
	}
}

void Grid::initializeRoad(){
	for (size_t i = 0; i < this->grid.size(); i++) {
		for (size_t j = 0; j < this->grid[i].size(); j++) {
			if (j > 10 && j < 20){
				if (j == 15 && (i % 3 == 0)){
					this->grid[i][j] = 2;
				}else{
					this->grid[i][j] = 1;
				}
			}
			else if (j == 10 || j == 20) {
				if (i % 2 == 0) {
					this->grid[i][j] = 3;
				}else{
					this->grid[i][j] = 2;
				}
			} 
			else{
				if ((j == 3 || j == 24) && (i % 10 == 0))
				{
					this->grid[i][j] = 4;
				}else{
					this->grid[i][j] = 0;
				}
			}
		}
	}
}

void Grid::drawRects(sf::RenderWindow * windowHandler){
	float boxHeight = this->screenHeight / (float)this->gridSize;
	float boxWidth = this->screenWidth / (float)this->gridSize;

	sf::Texture grassTexture;
	grassTexture.loadFromFile("Resources/grass1.png");

	for (size_t i = 0; i < this->gridSize; i++) {
		for (size_t j = 0; j < this->gridSize; j++){
			sf::Vector2f rectpos;
			rectpos.x = j * boxWidth;
			rectpos.y = i * boxHeight;

			sf::RectangleShape rectangle;
			rectangle.setSize(sf::Vector2f(boxWidth, boxHeight));
			rectangle.setPosition(rectpos);

			switch (grid[i + this->currentTick][j])
			{
			case 0: {
				rectangle.setTexture(&grassTexture);
				break;
			}
			case 1: {
				rectangle.setFillColor(sf::Color(54, 54, 54));
				break;
			}
			case 2: {
				rectangle.setFillColor(sf::Color(255, 255, 255));
				break;
			}
			case 3: {
				rectangle.setFillColor(sf::Color(255, 0, 0));
				break;
			}
			default:
				rectangle.setTexture(&grassTexture);
				break;
			}

			windowHandler->draw(rectangle);
		}
	}
}

void Grid::drawSprites(sf::RenderWindow * windowHandler){
	float boxHeight = this->screenHeight / (float)this->gridSize;
	float boxWidth = this->screenWidth / (float)this->gridSize;

	sf::Texture treeTexture;
	treeTexture.loadFromFile("Resources/tree.png");

	for (size_t i = 0; i < this->gridSize; i++) {
		for (size_t j = 0; j < this->gridSize; j++) {
			switch (this->grid[i + this->currentTick][j])
			{
			case 4: {
				sf::Sprite sprite;
				sprite.setTexture(treeTexture);
				sprite.setScale(0.05,0.05);
				sprite.setPosition(boxWidth * j, boxHeight * i);
				windowHandler->draw(sprite);
				break;
			}
			default:
				break;
			}
		}
	}
}

void Grid::drawPlayer(sf::RenderWindow * windowHandler){
	float boxHeight = this->screenHeight / (float)this->gridSize;
	float boxWidth = this->screenWidth / (float)this->gridSize;

	sf::Texture carTexture;
	carTexture.loadFromFile("Resources/car.png");

	sf::RectangleShape rectPlayer;
	rectPlayer.setSize(sf::Vector2f(boxWidth * 3, boxHeight * 2));
	rectPlayer.setTexture(&carTexture);
	rectPlayer.setRotation(-90);

	if (playerPos == 0){
		rectPlayer.setPosition(sf::Vector2f(boxWidth * 12, boxHeight * 25));
	}
	else{
		rectPlayer.setPosition(sf::Vector2f(boxWidth * 18, boxHeight * 25));
	}
	windowHandler->draw(rectPlayer);
}

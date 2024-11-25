#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class BoardManager
{
	Board* board;
	sf::RectangleShape rect;
	sf::RenderWindow* window;
	bool playing = false;
public:
	BoardManager(sf::RenderWindow* window, int width = 100,int height = 100);
	sf::Vector2f getSize() { return sf::Vector2f(board->getWidth(), board->getHeight()); }
	sf::Vector2i getGridPosition(sf::Vector2i pos) { return sf::Vector2i((int)(pos.x / cellSize().x), (int)(pos.y / cellSize().y)); }
	sf::Vector2f cellSize();
	void start();
	void stop();
	void reset();
	void draw();
	void update() { board->run(); };
	void handleInput(sf::Event event);
};
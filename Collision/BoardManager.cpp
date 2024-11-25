#include "BoardManager.h"
#include <iostream>

BoardManager::BoardManager(sf::RenderWindow* window, int width, int height):window(window) {
	board = new Board(width,height);
	rect = sf::RectangleShape(cellSize());
	rect.setFillColor(sf::Color::White);
	//std::cout << cellSize().x << " " << cellSize().y << std::endl;
	//board->setCell(10, 10, true);
}

sf::Vector2f BoardManager::cellSize() {
	sf::Vector2f v;
	v.x = window->getSize().x / getSize().x;
	v.y = window->getSize().y / getSize().y;

	return v;
}

void BoardManager::draw() {
	for (int x = 0; x < getSize().x; x++) {
		for (int y = 0; y < getSize().y; y++) {
			if (board->getCell(x,y)) {
				sf::RectangleShape r(cellSize());
				r.setFillColor(sf::Color::White);
				r.setPosition(sf::Vector2f(x * cellSize().x, y * cellSize().y));
				//std::cout << r.getPosition().x << " " << r.getPosition().y << std::endl;
				window->draw(r);
			}
		}
	}
}


void BoardManager::handleInput()
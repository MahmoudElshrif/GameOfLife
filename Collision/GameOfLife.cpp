#include <SFML/Graphics.hpp>
#include "BoardManager.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "Game of Life");
    BoardManager bm(&window);


    unsigned long long t = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            bm.handleInput(event);
        }

        sf::RectangleShape r(sf::Vector2f(100, 100));
        r.setPosition(10, 100);
        r.setFillColor(sf::Color::White);
        window.clear();

        bm.draw();

        t += 1;

        if (t >= 500) {
            bm.update();
            std::cout << "update\n";
            t = 0;
        }

        //std::cout << r.getPosition().x << " " << r.getPosition().y << std::endl;
        //window.draw(r);

        window.display();
    }

    return 0;
}
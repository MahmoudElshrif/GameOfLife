#include <SFML/Graphics.hpp>
#include "BoardManager.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "Game of Life");
    BoardManager bm(&window);


    unsigned long long t = 0;
    int updatetime = 300;
    bool running = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.scancode == sf::Keyboard::Scan::Space) {
                    //std::cout << "shit\n" << std::endl;
                    running = !running;
                    t = updatetime - 1;
                }
                if (event.key.scancode == sf::Keyboard::Scan::Q) {
                    bm.reset();
                }

                if (event.key.scancode == sf::Keyboard::Scan::W) {
                    bm.enableGrid();
                }
            }
            bm.handleInput(event);
        }

        sf::RectangleShape r(sf::Vector2f(100, 100));
        r.setPosition(10, 100);
        r.setFillColor(sf::Color::White);
        window.clear();

        bm.draw();

        if(running)
            t += 1;

        if (t >= updatetime) {
            bm.update();
            t = 0;
        }

        //std::cout << r.getPosition().x << " " << r.getPosition().y << std::endl;
        //window.draw(r);

        window.display();
    }

    return 0;
}
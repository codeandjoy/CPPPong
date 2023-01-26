#include <SFML/Graphics.hpp>

#include "Racket.h"

int main(){
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1000, 700), "Pong");

    Racket racket;

    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed) window->close();
        }

        window->clear();

        window->draw(racket);

        window->display();
    }

    return 0;
}
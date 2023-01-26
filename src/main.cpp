#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1000, 700), "Pong");

    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed) window->close();
        }

        window->display();
    }

    return 0;
}
#include <SFML/Graphics.hpp>

#include "Racket.h"

int main(){
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1000, 700), "Pong");

    Racket racket;


    sf::Clock deltaClock;
    while(window->isOpen()){
        // dt
        sf::Time deltaTime = deltaClock.restart();
        float dt = deltaTime.asSeconds();
        if(dt > .15) dt = .15;
        //

        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed) window->close();
        }

        // Controls
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            racket.setVelocityGoal(-600);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            racket.setVelocityGoal(600);
        }
        else{
            racket.setVelocityGoal(0);
        }
        //

        window->clear();

        racket.update(dt);

        window->draw(racket);

        window->display();
    }

    return 0;
}
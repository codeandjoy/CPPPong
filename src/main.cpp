#include <SFML/Graphics.hpp>

#include "Racket.h"
#include "Ball.h"
#include "./utils/keepWithinWindow.h"
#include "./utils/onCollision.h"

int main(){
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1000, 700), "Pong");

    Racket *racketP1 = new Racket();
    racketP1->setPosition(sf::Vector2f(1000/2+50, 700-50));
    Racket *racketP2 = new Racket();
    racketP2->setPosition(sf::Vector2f(1000/2+50, 50));
    Ball *ball = new Ball();

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
            racketP1->setVelocityGoal(-600);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            racketP1->setVelocityGoal(600);
        }
        else{
            racketP1->setVelocityGoal(0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            racketP2->setVelocityGoal(-600);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            racketP2->setVelocityGoal(600);
        }
        else{
            racketP2->setVelocityGoal(0);
        }
        //

        window->clear();

        racketP1->update(dt);
        racketP2->update(dt);
        ball->update(dt);

        onCollision(racketP1, ball, [ball](){
            ball->bounce();
        });
        onCollision(racketP2, ball, [ball](){
            ball->bounce();
        });

        keepWithinWindow(window, racketP1);
        keepWithinWindow(window, racketP2);
        keepWithinWindowWithResponse(window, ball, [ball](){
            ball->bounce();
        });

        window->draw(*racketP1);
        window->draw(*racketP2);
        window->draw(*ball);

        window->display();
    }

    return 0;
}
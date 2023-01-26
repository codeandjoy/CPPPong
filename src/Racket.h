#ifndef RACKET_H
#define RACKET_H

#include <SFML/Graphics.hpp>


class Racket : public sf::RectangleShape{
    public:
    Racket();
    void update(float dt);

    void setVelocityGoal(float goal);

    private:
    sf::Vector2f movementVector = sf::Vector2f(0, 0);
    float velocityGoal = 0;
};


#endif
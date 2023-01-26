#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball : public sf::Sprite{
    public:
    Ball();

    void update(float dt);
    void bounce();

    private:
    sf::Texture texture;
    sf::Vector2f movementVector = sf::Vector2f(500, 500);
};


#endif
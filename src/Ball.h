#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball : public sf::Sprite{
    public:
    Ball();

    void update(float dt);

    private:
    sf::Texture texture;
    sf::Vector2f movementVector = sf::Vector2f(100, 100);
};


#endif
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball : public sf::Sprite{
    public:
    Ball();

    private:
    sf::Texture texture;
};


#endif
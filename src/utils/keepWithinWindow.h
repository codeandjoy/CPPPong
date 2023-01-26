#ifndef KEEP_WITHIN_WINDOW_H
#define KEEP_WITHIN_WINDOW_H

#include <SFML/Graphics.hpp>

bool collidesLeft(sf::RenderWindow *window, sf::Sprite *obj){ return obj->getPosition().x < 0; }
bool collidesRight(sf::RenderWindow *window, sf::Sprite *obj){ return obj->getPosition().x + obj->getTexture()->getSize().x > window->getSize().x; }
bool collidesTop(sf::RenderWindow *window, sf::Sprite *obj){ return obj->getPosition().y < 0; }
bool collidesBottom(sf::RenderWindow *window, sf::Sprite *obj){ return obj->getPosition().y + obj->getTexture()->getSize().y > window->getSize().y; }

void keepWithinWindow(sf::RenderWindow *window, sf::Sprite *obj){
    int wSizeX = window->getSize().x;
    int wSizeY = window->getSize().y;

    if(collidesLeft(window, obj)) obj->setPosition(0, obj->getPosition().y);
    if(collidesRight(window, obj)) obj->setPosition(wSizeX - obj->getTexture()->getSize().x, obj->getPosition().y);
    if(collidesTop(window, obj)) obj->setPosition(obj->getPosition().x, 0);
    if(collidesBottom(window, obj)) obj->setPosition(obj->getPosition().x, wSizeY - obj->getTexture()->getSize().y);
}

void keepWithinWindowWithResponse(sf::RenderWindow *window, sf::Sprite *obj, std::function<void()> response){
    int wSizeX = window->getSize().x;
    int wSizeY = window->getSize().y;

    if(collidesLeft(window, obj) ||
        collidesRight(window, obj) ||
        collidesTop(window, obj) ||
        collidesBottom(window, obj)){

        response();
    }
}


#endif
#ifndef KEEP_WITHIN_WINDOW_H
#define KEEP_WITHIN_WINDOW_H

#include <SFML/Graphics.hpp>


void keepWithinWindow(sf::RenderWindow *window, sf::Sprite *obj){
    int wSizeX = window->getSize().x;
    int wSizeY = window->getSize().y;

    // Left
    if(obj->getPosition().x < 0) obj->setPosition(0, obj->getPosition().y);
    // Right
    if(obj->getPosition().x + obj->getTexture()->getSize().x > wSizeX) obj->setPosition(wSizeX - obj->getTexture()->getSize().x, obj->getPosition().y);
    // Top
    if(obj->getPosition().y < 0) obj->setPosition(obj->getPosition().x, 0);
    // Bottom
    if(obj->getPosition().y + obj->getTexture()->getSize().y > wSizeY) obj->setPosition(obj->getPosition().x, wSizeY - obj->getTexture()->getSize().y);
}


#endif
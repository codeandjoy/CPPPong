#ifndef ON_COLLISION_H
#define ON_COLLISION_H

#include <SFML/Graphics.hpp>


void onCollision(sf::Sprite *sp1, sf::Sprite *sp2, std::function<void()> response){
    if(sp1->getGlobalBounds().intersects(sp2->getGlobalBounds())){
        response();
    }
}


#endif
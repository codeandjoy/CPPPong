#include <filesystem>
#include "Ball.h"

Ball::Ball(){
    if(!texture.loadFromFile(std::filesystem::current_path().string() + "/src/assets/ball.png")){
        printf("Can not load ball texture\n");
        exit(1);
    }
    this->setTexture(texture);

    this->setPosition(sf::Vector2f(1000/2-5, 700/2-5));
}

void Ball::update(float dt){
    this->setPosition(this->getPosition() + movementVector * dt);
}

void Ball::bounce(){
    // btm right
    if(movementVector.x > 0 && movementVector.y > 0){
        movementVector = sf::Vector2f(movementVector.x, -movementVector.y);
    }
    // top right
    else if(movementVector.x > 0 && movementVector.y < 0){
        movementVector = sf::Vector2f(-movementVector.x, movementVector.y);
    }
    // top left
    else if(movementVector.x < 0 && movementVector.y < 0){
        movementVector = sf::Vector2f(movementVector.x, abs(movementVector.y));
    }
    // bottom right
    else if(movementVector.x < 0 && movementVector.y > 0){
        movementVector = sf::Vector2f(-movementVector.x, movementVector.y);
    }
}
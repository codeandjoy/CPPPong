#include "Racket.h"
#include "./utils/approach.h"

Racket::Racket(){
    this->setSize(sf::Vector2f(100, 10));
    this->setFillColor(sf::Color::White);
    this->setPosition(sf::Vector2f(100, 100));
}

void Racket::update(float dt){
    movementVector.x = approach(velocityGoal, movementVector.x, dt*5000);
    this->setPosition(this->getPosition() + movementVector * dt);
}

void Racket::setVelocityGoal(float goal){ velocityGoal = goal; }
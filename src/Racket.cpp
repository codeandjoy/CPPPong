#include <filesystem>
#include "Racket.h"
#include "./utils/approach.h"

Racket::Racket(){
    if(!texture.loadFromFile(std::filesystem::current_path().string() + "/src/assets/racket.png")){
        printf("Can not load racket texture\n");
        exit(1);
    }
    this->setTexture(texture);
    
    this->setPosition(sf::Vector2f(1000/2+50, 700-50));
}

void Racket::update(float dt){
    movementVector.x = approach(velocityGoal, movementVector.x, dt*5000);
    this->setPosition(this->getPosition() + movementVector * dt);
}

void Racket::setVelocityGoal(float goal){ velocityGoal = goal; }
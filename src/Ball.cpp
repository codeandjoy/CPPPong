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
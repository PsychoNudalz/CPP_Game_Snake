//
// Created by Nudalz on 16/07/2023.
//

#include "Apple.h"

Apple::Apple() {
    //MAGIC NUMBERS
    Vector2f startingPosition(400, 300);
    sprite.setSize(Vector2f(20,20));
    sprite.setFillColor(Color::Red);
    sprite.setPosition(startingPosition);
}

void Apple::setPosition(Vector2f newPosition) {
    sprite.setPosition(newPosition);
}

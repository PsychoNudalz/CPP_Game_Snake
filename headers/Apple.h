//
// Created by Nudalz on 16/07/2023.
//

#ifndef TESTGAME_APPLE_H
#define TESTGAME_APPLE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Apple {
private:
    RectangleShape sprite;
public:
    Apple();

    void setPosition(Vector2f newPosition);
    RectangleShape getSprite() {
        return sprite;
    }
};


#endif //TESTGAME_APPLE_H

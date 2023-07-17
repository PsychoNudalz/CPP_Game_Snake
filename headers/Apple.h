//
// Created by Nudalz on 16/07/2023.
//

#ifndef TESTGAME_APPLE_H
#define TESTGAME_APPLE_H

#include <SFML/Graphics.hpp>
#include "Cell.h"

using namespace sf;

class Apple {
private:

    RectangleShape shape;
    Sprite sprite;
    static Texture texture;
    std::string texturePath = "../assets/sprites/apple.png";
    Cell *cell = nullptr;
public:

    Apple();

    void setCell(Cell &newCell);
    void setPosition(Vector2f newPosition);
    Sprite &getSprite() {
        return sprite;
    }

    Cell *getCell() const;

    void collectApple();
};


#endif //TESTGAME_APPLE_H

//
// Created by Nudalz on 16/07/2023.
//

#ifndef TESTGAME_SNAKESECTION_H
#define TESTGAME_SNAKESECTION_H
#include <SFML/Graphics.hpp>

using namespace sf;

class SnakeSection {
private:
    Vector2f position;
    RectangleShape section;
    Vector2f startSize = Vector2f(20,20);
public:
    explicit SnakeSection(Vector2f startPosition);
    Vector2f getPosition() {
        return position;
    }

    void setPosition(Vector2f newPosition);
    RectangleShape getShape(){
        return section;
    }
    void update();
};


#endif //TESTGAME_SNAKESECTION_H

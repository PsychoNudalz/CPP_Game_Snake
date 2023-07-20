//
// Created by Nudalz on 16/07/2023.
//

#ifndef TESTGAME_SNAKESECTION_H
#define TESTGAME_SNAKESECTION_H
#include <SFML/Graphics.hpp>

using namespace sf;

class SnakeSection {
private:
    Vector2i position_grid;
    Vector2f position_pixel;
    Vector2f centre_p;
    RectangleShape sectionShape;
    Vector2f startSize = Vector2f(20,20);
public:
    explicit SnakeSection(Vector2f startPosition,Vector2f size);
    Vector2f getPosition_P() {
        return position_pixel;
    }

    void setPosition(Vector2f newPosition);
    RectangleShape getShape() const {
        return sectionShape;
    }
    void updateShape();

    bool isCollide(Rect<float> rectangleShape);
};


#endif //TESTGAME_SNAKESECTION_H

//
// Created by Nudalz on 16/07/2023.
//

#include "Wall.h"

Wall::Wall(Vector2f position, Vector2f size) {
    wallShape.setSize(size);
    wallShape.setFillColor(Color::White);
    wallShape.setPosition(position);
    this->position = position;

}

 Vector2f Wall::getPosition()  {
    return position;
}

 std::string Wall::getPosition_String()  {
    return std::to_string(getPosition().x) + ", " + std::to_string(getPosition().y);
}

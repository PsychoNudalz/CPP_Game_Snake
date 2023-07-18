//
// Created by Nudalz on 16/07/2023.
//

#include "SnakeSection.h"

SnakeSection::SnakeSection(Vector2f startPosition,Vector2f size) {
    section.setSize(startSize);
    section.setFillColor(Color::Green);
    section.setPosition(startPosition);
    position_pixel = startPosition;
    startSize = size;
}

void SnakeSection::setPosition(Vector2f newPosition) {
    position_pixel = newPosition;

}

void SnakeSection::update() {
    section.setPosition(position_pixel);
}

bool SnakeSection::isCollide(Rect<float> rectangleShape) {
    return (getShape().getGlobalBounds().intersects(rectangleShape));
}
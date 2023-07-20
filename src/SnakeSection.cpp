//
// Created by Nudalz on 16/07/2023.
//

#include "SnakeSection.h"

SnakeSection::SnakeSection(Vector2f startPosition,Vector2f size) {
    sectionShape.setSize(startSize);
    sectionShape.setFillColor(Color::Green);
    sectionShape.setPosition(startPosition);
    position_pixel = startPosition;
    startSize = size;
}

void SnakeSection::setPosition(Vector2f newPosition) {
    position_pixel = newPosition;

}

void SnakeSection::updateShape() {
    sectionShape.setPosition(position_pixel);

}

bool SnakeSection::isCollide(Rect<float> rectangleShape) {
    return (getShape().getGlobalBounds().intersects(rectangleShape));
}

void SnakeSection::setColour(Color colour) {
    sectionShape.setFillColor(colour);

}

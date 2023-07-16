//
// Created by Nudalz on 16/07/2023.
//

#include "SnakeSection.h"

SnakeSection::SnakeSection(Vector2f startPosition) {
    section.setSize(startSize);
    section.setFillColor(Color::Green);
    section.setPosition(startPosition);
    position = startPosition;
}

void SnakeSection::setPosition(Vector2f newPosition) {
    position = newPosition;

}

void SnakeSection::update() {
    section.setPosition(position);
}

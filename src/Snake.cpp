//
// Created by Nudalz on 18/07/2023.
//

#include "Snake.h"
Snake::Snake(int length, Vector2f &cellSize) {
    sections.clear();

    size = length;
    CellVector = cellSize;
    for (int i = 0; i < length; ++i) {
        addSection();
    }
}

const vector<SnakeSection> &Snake::getSections() const {
    return sections;
}

void Snake::addSection() {
    Vector2f newSectionPosition =tail().getPosition();
    sections.emplace_back(newSectionPosition,CellVector);
}

SnakeSection &Snake::head() {
    return sections[0];
}

SnakeSection &Snake::tail() {
    return sections[sections.size()-1];
}






//
// Created by Nudalz on 18/07/2023.
//

#include "Snake.h"


Snake::Snake() = default;


Snake::Snake(int length, Vector2f &cellSize,Vector2f position) {
    sections.clear();
    CellVector = cellSize;
    sections.emplace_back(position, CellVector);

    for (int i = 1; i < length; ++i) {
        addSection();
    }
}

vector<SnakeSection> &Snake::getSections() {
    return sections;
}

void Snake::addSection() {
    Vector2f newSectionPosition = tail().getPosition_P();
    sections.emplace_back(newSectionPosition, CellVector);
}

SnakeSection &Snake::head() {
    return sections[0];
}

SnakeSection &Snake::tail() {
    return sections[sections.size() - 1];
}

SnakeSection &Snake::getSection(int i) {
    return sections[i];
}

unsigned int Snake::size() {
    return sections.size();
}






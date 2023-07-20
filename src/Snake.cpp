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

    updateColour();
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

void Snake::updateColour() {
    for (float i = 0; i < sections.size(); ++i) {
        sections[i].setColour(getLerpColour((float)(i/(sections.size()-1))));
    }
}

Color Snake::getLerpColour(float f) {
    float inv = 1-f;
    Vector3i tailColour_Temp = Vector3i(tailColour.x*f,tailColour.y*f,tailColour.z*f);
    Vector3i headColour_Temp = Vector3i(headColour.x*inv,headColour.y*inv,headColour.z*inv);
    headColour_Temp = headColour_Temp+tailColour_Temp;
    return Color(headColour_Temp.x,headColour_Temp.y,headColour_Temp.z);
}






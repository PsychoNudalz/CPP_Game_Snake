//
// Created by Nudalz on 17/07/2023.
//

#include "Cell.h"

Cell::Cell(Vector2f p_Position, Vector2i g_Position, Vector2f size,CellType cType) {
    cellType =cType;
    position_grip = g_Position;
    position_pixel = p_Position;
    cellShape.setSize(size);
    cellShape.setFillColor(fillColor);
    cellShape.setOutlineColor(borderColor);
    cellShape.setOutlineThickness(outline);
    cellShape.setPosition(position_pixel);
    colliderShape.setSize(size);
    colliderShape.setPosition(position_pixel);


}

 Vector2i &Cell::getGridPosition()  {
    return position_grip;
}

 Vector2f &Cell::getPixelPosition()  {
    return position_pixel;
}

std::string Cell::getPosition_String() {
    return std::to_string(getGridPosition().x) + ", " + std::to_string(getGridPosition().y);

}

 RectangleShape &Cell::getColliderShape()  {
    return colliderShape;
}

void Cell::setCellType(int cellType) {
    Cell::cellType = cellType;
}

int Cell::getCellType() const {
    return cellType;
}



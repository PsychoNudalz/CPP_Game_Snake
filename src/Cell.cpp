//
// Created by Nudalz on 17/07/2023.
//

#include "Cell.h"

Cell::Cell(Vector2f p_Position, Vector2i g_Position, Vector2f size,CellType cType) {
    cellType =cType;
    gridPosition = g_Position;
    pixelPosition = p_Position;
    cellShape.setSize(size);
    cellShape.setFillColor(fillColor);
    cellShape.setOutlineColor(borderColor);
    cellShape.setOutlineThickness(outline);
    cellShape.setPosition(pixelPosition);
    colliderShape.setSize(size);
    colliderShape.setPosition(pixelPosition);


}

const Vector2i &Cell::getGridPosition() const {
    return gridPosition;
}

const Vector2f &Cell::getPixelPosition() const {
    return pixelPosition;
}

std::string Cell::getPosition_String() {
    return std::to_string(getGridPosition().x) + ", " + std::to_string(getGridPosition().y);

}

const RectangleShape &Cell::getColliderShape() const {
    return colliderShape;
}



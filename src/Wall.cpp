//
// Created by Nudalz on 16/07/2023.
//

#include "Wall.h"

Wall::Wall(const Vector2f &pPosition, const Vector2i &gPosition, const Vector2f &size, const CellType &cType)
        : Cell(pPosition, gPosition, size, cType) {
    cellType = CellType::WALL;
    position_grip = gPosition;
    position_pixel = pPosition;
    cellShape.setSize(size);
    cellShape.setFillColor(wallColour);
    cellShape.setOutlineColor(borderColor);
    cellShape.setOutlineThickness(outline);
    cellShape.setPosition(position_pixel);
    colliderShape.setSize(size);
    colliderShape.setPosition(position_pixel);
}

//
// Created by Nudalz on 16/07/2023.
//

#include "Wall.h"

Wall::Wall(const Vector2f &pPosition, const Vector2i &gPosition, const Vector2f &size, const CellType &cType)
        : Cell(pPosition, gPosition, size, cType) {
    cellType = cType;
    gridPosition = gPosition;
    pixelPosition = pPosition;
    cellShape.setSize(size);
    cellShape.setFillColor(wallColour);
    cellShape.setOutlineColor(borderColor);
    cellShape.setOutlineThickness(outline);
    cellShape.setPosition(pixelPosition);
    colliderShape.setSize(size);
    colliderShape.setPosition(pixelPosition);
}

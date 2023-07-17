//
// Created by Nudalz on 16/07/2023.
//

#include <iostream>
#include "Apple.h"

Apple::Apple() {
    shape.setSize(Vector2f(20,20));
    shape.setFillColor(Color::Blue);
   if(!texture.loadFromFile(texturePath)){
       std::cout<<"Load texture FAILED: "<<texturePath<<"\n";
   }
    sprite.setTexture(texture);
}

void Apple::setPosition(Vector2f newPosition) {
    sprite.setPosition(newPosition);
    shape.setPosition(newPosition);
}

void Apple::setCell(Cell &newCell) {
    cell = &newCell;
    setPosition(cell->getPixelPosition());
}



void Apple::collectApple() {
    cell->setCellType(Cell::CellType::NONE);
}

Cell *Apple::getCell() const {
    return cell;
}








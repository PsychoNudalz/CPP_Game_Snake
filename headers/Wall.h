//
// Created by Nudalz on 16/07/2023.
//

#ifndef TESTGAME_WALL_H
#define TESTGAME_WALL_H

#include <SFML/Graphics.hpp>
#include "Cell.h"

using namespace sf;

class Wall : public Cell{
protected:
    Color wallColour = Color::White;
public:
    Wall(const Vector2f &pPosition, const Vector2i &gPosition, const Vector2f &size, const CellType &cType);
};


#endif //TESTGAME_WALL_H

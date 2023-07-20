//
// Created by Nudalz on 18/07/2023.
//

#ifndef TESTGAME_SNAKE_H
#define TESTGAME_SNAKE_H

#include "SnakeSection.h"
#include <vector>
#include <iostream>


using namespace sf;
using namespace std;


class Snake {
private:
    vector<SnakeSection> sections = vector<SnakeSection>();
    Vector2f CellVector = Vector2f(0,0);
    Vector3i headColour = Vector3i (0,255,0);
    Vector3i tailColour = Vector3i (150,255,150);
public:
    Snake();
    Snake(int length,Vector2f &cellSize,Vector2f position);

     vector<SnakeSection> &getSections() ;
     SnakeSection &getSection(int i) ;
    SnakeSection &head();
    SnakeSection &tail();
    void addSection();
    unsigned int size();
    void updateColour();
    Color getLerpColour(float f);
};


#endif //TESTGAME_SNAKE_H

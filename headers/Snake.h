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
    vector<SnakeSection> sections;
    int size = 0;
    Vector2f CellVector;
public:
    Snake(int length,Vector2f &cellSize);

    const vector<SnakeSection> &getSections() const;
    SnakeSection &head();
    SnakeSection &tail();
    void addSection();
};


#endif //TESTGAME_SNAKE_H

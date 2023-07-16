//
// Created by Nudalz on 16/07/2023.
//

#ifndef TESTGAME_ENGINE_H
#define TESTGAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "SnakeSection.h"
#include "Apple.h"
#include <vector>
#include <deque>

using namespace sf;
using namespace std;

class Engine {
private:
    Vector2f resolution;
    RenderWindow window = RenderWindow();
    const std::string Title = "Amazing Test Game";
    const unsigned int FPS = 60;
    const  float SegmentSize = 20;
    static const Time TimePerFrame;

    vector<SnakeSection> snake;

    int snakeDirection;
    deque<int> directionQueue; // queue for direction key processing
    int speed;
    int sectionsToAdd;

    Apple apple;

    Time timeSinceLastMove;

public:


    Engine();

    void draw();

    //Main loop
    void run();

    void input();

    enum Direction {
        UP, RIGHT, DOWN, LEFT
    };

    void addDirection(int newDirection);

    void update();

    void newSnake();

    void addSnakeSection();

    void moveApple();
};


#endif //TESTGAME_ENGINE_H

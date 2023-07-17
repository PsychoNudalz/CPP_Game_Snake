//
// Created by Nudalz on 16/07/2023.
//

#ifndef TESTGAME_ENGINE_H
#define TESTGAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "SnakeSection.h"
#include "Apple.h"
#include "Wall.h"
#include <vector>
#include <deque>
#include <fstream>
#include <iostream>


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
    vector<Wall> wallSections;
    int currentLevel;
    int maxLevels;
    vector<string> levels;

    Time timeSinceLastMove;

    int currentGameState;
    int lastGameState;

    void collisionDetection();
    void updateSnake();

public:


    Engine();

    enum GameState {RUNNING, PAUSED, GAMEOVER};

    void draw();

    static void setupText(Text *textItem,const Font &font, const String &value, int size, Color colour);

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
    void checkLevelFiles();
    void loadLevel(int levelNumber);

    void togglePause();
    void startGame();
};


#endif //TESTGAME_ENGINE_H

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
#include "Cell.h"

#include <vector>
#include <deque>
#include <fstream>
#include <iostream>


using namespace sf;
using namespace std;

class Engine {
private:
    Vector2f resolution;
    const Vector2f StartResolution = Vector2f(800, 600);
    RenderWindow window = RenderWindow();
    const std::string Title = "Amazing Test Game";
    const unsigned int FPS = 60;
    int randSeed = 2;

    static const Time TimePerFrame;
    Time timeSinceLastMove;

    //Cell Properties

    const  float CellSize = 20;
    Vector2f CellVector;
    Vector2i cellsInGrid;//X is columns, Y is rows.
    vector<vector<Cell>> cells;


    //Snake Properties
    vector<SnakeSection> snake;
    int snakeDirection;
    deque<int> directionQueue; // queue for direction key processing
    int speed;
    int sectionsToAdd;

    //Apple Properties
    Apple apple;

    //Wall Properties
    vector<Wall> wallSections;

    //Level Properties
    int currentLevel;
    int maxLevels;
    vector<string> levels;

    //Text
    Font mainFont;
    Text titleText;


    int currentGameState;
    int lastGameState;

    void collisionDetection();
    void updateSnake();
    void initialiseCells();

public:


    explicit Engine();

    enum GameState {RUNNING, PAUSED, GAMEOVER};

     vector<vector<Cell>> &getCells() ;

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

    float getCellSize() const;
    Vector2f getCellVector2();


};


#endif //TESTGAME_ENGINE_H

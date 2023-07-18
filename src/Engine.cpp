//
// Created by Nudalz on 16/07/2023.
//

#include "Engine.h"


const sf::Time Engine::TimePerFrame = seconds(1.f / 60.f);

Engine::Engine() {
    resolution = StartResolution;
    window.create(VideoMode(resolution.x, resolution.y), Title, Style::Default);
    window.setFramerateLimit(FPS);
    maxLevels = 0;

    CellVector = Vector2f(CellSize, CellSize);


    initialiseCells();
    apple = Apple();
    apple.setCell(cells[0][0]);

    checkLevelFiles();


    startGame();


    mainFont.loadFromFile("../assets/fonts/PressStart2P-Regular.ttf");


    setupText(&titleText, mainFont, "SNAKE", 20, Color::Blue);
    FloatRect titleTextBounds = titleText.getLocalBounds();
    titleText.setPosition(Vector2f(resolution.x / 2 - titleTextBounds.width / 2, 0));
}

void Engine::run() {

    Clock clock;

    while (window.isOpen()) {
        Time dt = clock.restart();// delta time


        if (currentGameState == GameState::PAUSED || currentGameState == GameState::GAMEOVER) {
            input();
            if (currentGameState == GameState::GAMEOVER) {
                draw();
            }
            sleep(milliseconds(2));
            continue;
        } else {

            timeSinceLastMove += dt;


            input();
            update();
            draw();
        }
    }
}

void Engine::newSnake() {
    snake.clear();
    snake.emplace_back(Vector2f(CellSize * 5, CellSize * 5));
    snake.emplace_back(Vector2f(CellSize * 4, CellSize * 5));
    snake.emplace_back(Vector2f(CellSize * 3, CellSize * 5));
}

void Engine::addSnakeSection() {
    Vector2f newSectionPosition = snake[snake.size() - 1].getPosition();
    snake.emplace_back(newSectionPosition);
}

void Engine::moveApple() {
    //Find a location

    Cell appleCell = cells[0][0];
    Vector2f &newAppleLocation = appleCell.getPixelPosition();
    bool badLocation = false;
    int row = 0;
    int column = 0;
//    rand(time(NULL) + randSeed);

    //loop until we find a valid location
    do {
        badLocation = false;

        //1 is for 1 segment offset from the wall
//        newAppleLocation.row = (float) (1 + rand() / ((RAND_MAX + 1u) / (int) appleResolution.row)) * CellSize;
//        newAppleLocation.column = (float) (1 + rand() / ((RAND_MAX + 1u) / (int) appleResolution.column)) * CellSize;

        column = (1 + rand() / ((RAND_MAX + 1u) / (int) cellsInGrid.x)) % cellsInGrid.x;
        row = (1 + rand() / ((RAND_MAX + 1u) / (int) cellsInGrid.y)) % cellsInGrid.y;
        appleCell = cells[column][row];
        newAppleLocation = appleCell.getPixelPosition();
        if (appleCell.getCellType() != Cell::CellType::NONE) {
            badLocation = true;
        }
        if (!badLocation) {
            //Check spawn collision
            for (auto &s: snake) {
                if (s.getShape().getGlobalBounds().intersects(
                        Rect<float>(newAppleLocation.x, newAppleLocation.y, CellSize, CellSize))) {
                    badLocation = true;
                    break;
                }
            }
//            //check for apple on wall
//            for (auto &w: wallSections) {
//                if (w.getShape().getGlobalBounds().intersects(
//                        Rect<float>(newAppleLocation.row, newAppleLocation.column, CellSize, CellSize))) {
//                    badLocation = true;
//                    break;
//                }
//            }
        }

    } while (badLocation);

    apple.setCell(cells[column][row]);
}

void Engine::togglePause() {
    if (currentGameState == GameState::RUNNING) {
        lastGameState = currentGameState;
        currentGameState = GameState::PAUSED;

    } else if (currentGameState == GameState::PAUSED) {
        currentGameState = lastGameState;


    }
    switch (currentGameState) {
        case GameState::RUNNING:
            std::cout << "Current state: Running\n";
            break;
        case GameState::PAUSED:
            std::cout << "Current state: Paused\n";
            break;
        case GameState::GAMEOVER:
            std::cout << "Current state: Game Over\n";
            break;
    }

}

void Engine::startGame() {

    speed = 2;
    snakeDirection = Direction::RIGHT;
    sectionsToAdd = 0;
    timeSinceLastMove = Time::Zero;
    currentGameState = GameState::RUNNING;
    directionQueue.clear();
    currentLevel = 1;
    loadLevel(currentLevel);
    newSnake();
    moveApple();
    lastGameState = currentGameState;
}


/**
 * check level manifest file and make sure it can open
 */
void Engine::checkLevelFiles() {
    //load
    ifstream levelsManifest("../assets/levels/levels.txt");
//    levelsManifest.open();
    ifstream testFile;
    if (levelsManifest.is_open()) {
        std::cout << "Level manifest read clear\n";

    }
    for (string manifestLine; getline(levelsManifest, manifestLine);) {
        std::string currentLevelPath = "../assets/levels/" + manifestLine;

        //check if it can open the level
        testFile.open(currentLevelPath);
        if (testFile.is_open()) {
            levels.emplace_back(currentLevelPath);
            testFile.close();
            maxLevels++;
        }
    }
    levelsManifest.close();
    std::cout << "Level checked: " << maxLevels << " of levels\n";
}

/**
 * load a level, set walls on "x"
 */
void Engine::loadLevel(int levelNumber) {
    //Level names starts at 1
    string levelFile = levels[levelNumber - 1];
    ifstream level(levelFile);
    string line;
    Cell current = cells[0][0];
    if (level.is_open()) {
        for (int y = 0; y < cellsInGrid.y; ++y) {
            getline(level, line);
            for (int x = 0; x < cellsInGrid.x; ++x) {
                if (line[x] == 'x') {
                    current = cells[x][y];
                    Wall wall = Wall(current.getPixelPosition(), current.getGridPosition(), CellVector,
                                     Cell::CellType::WALL);

                    cells[x][y] = wall;
                    wallSections.emplace_back(wall);
                }
            }
        }

    }
    level.close();

}

void Engine::setupText(Text *textItem, const Font &font, const String &value, int size, Color colour) {
    textItem->setFont(font);
    textItem->setString(value);
    textItem->setCharacterSize(size);
    textItem->setFillColor(colour);
}


float Engine::getCellSize() const {
    return CellSize;
}

Vector2f Engine::getCellVector2() {
    return CellVector;
}

void Engine::initialiseCells() {
    cellsInGrid = Vector2i(resolution.x / CellSize, resolution.y / CellSize);
    int xSize = cellsInGrid.x;
    int ySize = cellsInGrid.y;
    vector<Cell> column;
    for (int x = 0; x < xSize; ++x) {

        column = vector<Cell>();
        for (int y = 0; y < ySize; ++y) {

            column.emplace_back(Vector2f(x * CellSize, y * CellSize), Vector2i(x, y), CellVector, Cell::CellType::NONE);
        }
        cells.emplace_back(column);
    }
}

vector<vector<Cell>> &Engine::getCells() {
    return cells;
}



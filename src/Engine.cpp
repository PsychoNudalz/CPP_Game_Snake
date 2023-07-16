//
// Created by Nudalz on 16/07/2023.
//

#include "Engine.h"


const sf::Time Engine::TimePerFrame = seconds(1.f / 60.f);

Engine::Engine() {
    resolution = Vector2f(800, 600);
    window.create(VideoMode(resolution.x, resolution.y), Title, Style::Default);
    window.setFramerateLimit(FPS);

    speed = 2;
    snakeDirection = Direction::RIGHT;
    sectionsToAdd = 0;
    timeSinceLastMove = Time::Zero;

    newSnake();
    moveApple();

}

void Engine::run() {

    Clock clock;

    while (window.isOpen()) {
        Time dt = clock.restart();// delta time
        timeSinceLastMove += dt;


        input();
        update();
        draw();
    }
}

void Engine::newSnake() {
    snake.clear();
    snake.emplace_back(Vector2f(SegmentSize * 5, SegmentSize * 5));
    snake.emplace_back(Vector2f(SegmentSize * 4, SegmentSize * 5));
    snake.emplace_back(Vector2f(SegmentSize * 3, SegmentSize * 5));
}

void Engine::addSnakeSection() {
    Vector2f newSectionPosition = snake[snake.size() - 1].getPosition();
    snake.emplace_back(newSectionPosition);
}

void Engine::moveApple() {
    //Find a location

    Vector2f appleResolution = Vector2f(resolution.x / 20 - 2, resolution.y / 20 - 2);
    Vector2f newAppleLocation;
    bool badLocation = false;
    srand(time(nullptr));
    //loop until we find a valid location
    do {
        badLocation = false;

        //1 is for 1 segment offset from the wall
        newAppleLocation.x = (float) (1 + rand() / ((RAND_MAX + 1u) / (int) appleResolution.x)) * SegmentSize;
        newAppleLocation.y = (float) (1 + rand() / ((RAND_MAX + 1u) / (int) appleResolution.y)) * SegmentSize;

        for (auto &s: snake) {
            if (s.getShape().getGlobalBounds().intersects(
                    Rect<float>(newAppleLocation.x, newAppleLocation.y, SegmentSize, SegmentSize))) {
                badLocation = true;
                break;
            }
        }
        //TODO - add check for apple on wall
    } while (badLocation);

    apple.setPosition(newAppleLocation);

}



//
// Created by Nudalz on 16/07/2023.
//
#include <iostream>
#include "Engine.h"

void Engine::update() {
    if (timeSinceLastMove.asSeconds() >= seconds(1.f / float(speed)).asSeconds()) {
        Vector2f thisSectionPosition = snake.head().getPosition_P();
        Vector2f lastSectionPosition = thisSectionPosition;

        if (!directionQueue.empty()) {
            //prevent going back
            switch (snakeDirection) {
                case Direction::UP:
                    if (directionQueue.front() != Direction::DOWN) {
                        snakeDirection = directionQueue.front();
                    }
                    break;
                case Direction::DOWN:
                    if (directionQueue.front() != Direction::UP) {
                        snakeDirection = directionQueue.front();
                    }
                    break;
                case Direction::LEFT:
                    if (directionQueue.front() != Direction::RIGHT) {
                        snakeDirection = directionQueue.front();
                    }
                    break;
                case Direction::RIGHT:
                    if (directionQueue.front() != Direction::LEFT) {
                        snakeDirection = directionQueue.front();
                    }
                    break;

            }
            directionQueue.pop_front();
        }
        //grow the snake
        if (sectionsToAdd) {
            addSnakeSection();
            sectionsToAdd--;

        }

        //updateShape snake
        //head
        switch (snakeDirection) {
            case Direction::RIGHT:
                snake.head().setPosition(Vector2f(thisSectionPosition.x + CellSize, thisSectionPosition.y));
                break;
            case Direction::LEFT:
                snake.head().setPosition(Vector2f(thisSectionPosition.x - CellSize, thisSectionPosition.y));
                break;
            case Direction::UP:
                snake.head().setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y - CellSize));
                break;
            case Direction::DOWN:
                snake.head().setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y + CellSize));
                break;
        }
        //tail
        for (int s = 1; s < snake.size(); ++s) {
            thisSectionPosition = snake.getSection(s).getPosition_P();
            snake.getSection(s).setPosition(lastSectionPosition);
            lastSectionPosition = thisSectionPosition;
        }

        //run snake sectionShape updateShape functions
        updateSnake();

        //Collision detection - Apple
        collisionDetection();


        //reset time
        timeSinceLastMove = Time::Zero;
    }
    //END updateShape snake position_pixel
}

void Engine::collisionDetection() {
    //Apple
    if (snake.head().isCollide(apple.getSprite().getGlobalBounds())) {
        // we hit the apple, add more sections to the snake
        sectionsToAdd += 4;
        speed++;
        apple.collectApple();
        moveApple();
    }

    //Snake
    if (snake.size() > snakeStartSize) {
        for (int s = 1; s < snake.size(); ++s) {
            if (snake.head().isCollide(snake.getSection(s).getShape().getGlobalBounds())) {
                std::cout << "Snake crashed to segment: " << s << "\n";
                currentGameState = GameState::GAMEOVER;
                break;
            }
        }
    }

    //Wall
    for (auto &w: wallSections) {
        if (snake.head().isCollide(w.getColliderShape().getGlobalBounds())) {
            std::cout << "Snake crashed to segment: " << w.getPosition_String() << "\n";
            currentGameState = GameState::GAMEOVER;
        }
    }


}

void Engine::updateSnake() {
    for (auto &s: snake.getSections()) {
        s.updateShape();
    }
}






//
// Created by Nudalz on 16/07/2023.
//
#include "Engine.h"

void Engine::update() {
    if (timeSinceLastMove.asSeconds() >= seconds(1.f / float(speed)).asSeconds()) {
        Vector2f thisSectionPosition = snake[0].getPosition();
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
        if (sectionsToAdd){
            addSnakeSection();
            sectionsToAdd--;

        }

        //update snake
        //head
        switch (snakeDirection) {
            case Direction::RIGHT:
                snake[0].setPosition(Vector2f(thisSectionPosition.x + SegmentSize, thisSectionPosition.y));
                break;
            case Direction::LEFT:
                snake[0].setPosition(Vector2f(thisSectionPosition.x - SegmentSize, thisSectionPosition.y));
                break;
            case Direction::UP:
                snake[0].setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y - SegmentSize));
                break;
            case Direction::DOWN:
                snake[0].setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y + SegmentSize));
                break;
        }
        //tail
        for (int s = 1; s < snake.size(); ++s) {
            thisSectionPosition = snake[s].getPosition();
            snake[s].setPosition(lastSectionPosition);
            lastSectionPosition = thisSectionPosition;
        }

        //run snake section update functions
        for (auto & s :snake){
            s.update();
        }

        //Collision detection - Apple
        if(snake[0].getShape().getGlobalBounds().intersects(apple.getSprite().getGlobalBounds())){
            // we hit the apple, add more sections to the snake
            //TODO - increment score
            sectionsToAdd += 4;
            speed ++;
            moveApple();
        }
        

        //reset time
        timeSinceLastMove = Time::Zero;
    }
    //END update snake position
}
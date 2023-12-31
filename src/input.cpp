//
// Created by Nudalz on 16/07/2023.
//
#include "Engine.h"

void Engine::input() {
    Event event{};
    while (window.pollEvent(event)) {
        //window close
        if (event.type == Event::Closed) {
            window.close();
        }
        //keyboard input
        if (event.type == Event::KeyPressed) {


            //Move Apple
            if (event.key.code == Keyboard::X) {
                moveApple();
            }

            //Pause
            if (event.key.code == Keyboard::P) {
                togglePause();
            }
            //Quit
            if (event.key.code == Keyboard::Escape) {
                window.close();
            }
            //New Game
            if(currentGameState == GameState::GAMEOVER){
                if(event.key.code== Keyboard::Enter){
                    startGame();
                }
            }

            //direction
            if (event.key.code == Keyboard::Up) {
                addDirection(Direction::UP);
            } else if (event.key.code == Keyboard::Down) {
                addDirection(Direction::DOWN);
            } else if (event.key.code == Keyboard::Left) {
                addDirection(Direction::LEFT);
            } else if (event.key.code == Keyboard::Right) {
                addDirection(Direction::RIGHT);
            }

        }
    }
}

void Engine::addDirection(int newDirection) {
    if (directionQueue.empty()) {
        directionQueue.emplace_back(newDirection);
    } else {
        if (directionQueue.back() != newDirection) {
            directionQueue.emplace_back(newDirection);

        }
    }
}








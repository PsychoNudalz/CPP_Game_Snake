//
// Created by Nudalz on 16/07/2023.
//

#include "Engine.h"

void Engine::draw() {
    window.clear(Color::Black);

    //draw cells
    for (auto &r:cells) {
        for (auto & c: r){
            window.draw(c.getShape());

        }
    }

    //draw walls
//    for (auto & w:wallSections){
//        window.draw(w.getShape());
//    }

    //draw apple
    window.draw(apple.getSprite());

    //draw snake
    for (auto & s : snake.getSections()) {
        window.draw(s.getShape());
    }

    //Draw Tet
    window.draw(titleText);

    window.display();
}



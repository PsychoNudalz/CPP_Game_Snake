//
// Created by Nudalz on 16/07/2023.
//

#include "Engine.h"

void Engine::draw() {
    window.clear(Color::Black);

    //draw walls
    for (auto & w:wallSections){
        window.draw(w.getShape());
    }

    //draw apple
    window.draw(apple.getSprite());

    //draw snake
    for (auto & s : snake) {
        window.draw(s.getShape());
    }

    //Draw Tet
    window.draw(titleText);
    
    window.display();
}



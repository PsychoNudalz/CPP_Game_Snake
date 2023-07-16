//
// Created by Nudalz on 16/07/2023.
//

#include "engine.hpp"



const sf::Time Engine::TimePerFrame = seconds(1.f/60.f);

Engine::Engine() {
    resolution = Vector2f (800,600);
    window.create(VideoMode(resolution.x,resolution.y),Title,Style::Default);
    window.setFramerateLimit(FPS);
}

void Engine::run() {
    while (window.isOpen()){
        draw();
    }
}



//
// Created by Nudalz on 16/07/2023.
//

#ifndef TESTGAME_ENGINE_HPP
#define TESTGAME_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "SFML/Graphics/RectangleShape.hpp"

using namespace sf;
using namespace std;

class Engine {
private:
    Vector2f resolution;
    RenderWindow window = RenderWindow();
    const std::string Title = "Amazing Test Game";
    const unsigned int FPS = 60;
    static const Time TimePerFrame;

public:

    Engine();

    void draw();

    //Main loop
    void run();
};


#endif //TESTGAME_ENGINE_HPP

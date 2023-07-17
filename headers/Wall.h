//
// Created by Nudalz on 16/07/2023.
//

#ifndef TESTGAME_WALL_H
#define TESTGAME_WALL_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Wall {
private:
    RectangleShape wallShape;
    Vector2f position;
public:
    Wall(Vector2f position, Vector2f size);
    RectangleShape getShape(){
        return wallShape;
    }

     Vector2f getPosition() ;
     std::string getPosition_String() ;

};


#endif //TESTGAME_WALL_H

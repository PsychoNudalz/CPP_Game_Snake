//
// Created by Nudalz on 17/07/2023.
//

#ifndef TESTGAME_CELL_H
#define TESTGAME_CELL_H


#include <SFML/Graphics.hpp>

using namespace sf;
class Cell {
protected:
    int cellType = CellType::NONE;
    RectangleShape cellShape;
    RectangleShape colliderShape;
    Vector2i gridPosition;
    Vector2f pixelPosition;
    Color fillColor = Color::Magenta;
    Color borderColor = Color(100,100,100);
    float outline = 1.f;
public:
    enum CellType {
        NONE,WALL,APPLE
    };
    Cell(Vector2f p_Position,Vector2i g_Position, Vector2f size,CellType cType);
    RectangleShape getShape(){
        return cellShape;
    }



     Vector2i &getGridPosition() ;

     Vector2f &getPixelPosition() ;
    std::string getPosition_String() ;

     RectangleShape &getColliderShape() ;

    int getCellType() const;

    void setCellType(int cellType);
};


#endif //TESTGAME_CELL_H

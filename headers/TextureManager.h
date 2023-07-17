//
// Created by Nudalz on 17/07/2023.
//

#ifndef TESTGAME_TEXTUREMANAGER_H
#define TESTGAME_TEXTUREMANAGER_H
#include <SFML/Graphics.hpp>

using namespace sf;


class TextureManager {
public:
    static Texture appleTexture;
    std::string appleTexturePath = "../assets/sprites/apple.png";


    explicit TextureManager();

    static const Texture &getAppleTexture();
};


#endif //TESTGAME_TEXTUREMANAGER_H

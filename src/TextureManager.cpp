//
// Created by Nudalz on 17/07/2023.
//

#include <iostream>
#include "TextureManager.h"

Texture TextureManager::appleTexture = Texture();

TextureManager::TextureManager(){
    if(!appleTexture.loadFromFile(appleTexturePath)){
        std::cout<<"Load apple texture FAILED: "<<appleTexturePath<<"\n";
    }
}

const Texture &TextureManager::getAppleTexture() {
    return appleTexture;
}




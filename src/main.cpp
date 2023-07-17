#include "Engine.h"
#include "TextureManager.h"
int main() {
    TextureManager textureManager = TextureManager();

    Engine engine;
    engine.run();

    return 0;
}

#include "GameEngine.h"
int main(int argc, char* argv[]) {
    GameEngine game;
    if (!game.Initialize()) {
        return 1;
    }
    game.Run();
    return 0;
}
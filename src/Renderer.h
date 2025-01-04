#pragma once

#include <SDL.h>

class Renderer {
public:
    Renderer(int width, int height);
    ~Renderer();

    bool Initialize();
    void ClearScreen();
    void DrawRect(int x, int y, int width, int height, SDL_Color color);
    void Present();

private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
};

#include "Renderer.h"
#include <iostream>

Renderer::Renderer(int width, int height) : window_(nullptr), renderer_(nullptr)
{
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

bool Renderer::Initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }

    window_ = SDL_CreateWindow("Awake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window_) {
        std::cout << "Window creation failed: " << SDL_GetError() << std::endl;
        return false;
    }
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer_) {
        std::cout << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}
void Renderer::ClearScreen() {
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);
}
void Renderer::DrawRect(int x, int y, int width, int height, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    SDL_Rect rect{ x,y, width,height };
    SDL_RenderFillRect(renderer_, &rect);

}
void Renderer::Present() {
    SDL_RenderPresent(renderer_);
}

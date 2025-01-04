#include "InputManager.h"
#include <iostream>

InputManager::InputManager()
{
}
InputManager::~InputManager()
{
}
void InputManager::HandleInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        }
        if (event.type == SDL_KEYDOWN) {
            keyStates_[event.key.keysym.scancode] = true;
        }
        else if (event.type == SDL_KEYUP) {
            keyStates_[event.key.keysym.scancode] = false;
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            mouseButtonStates_[event.button.button] = true;
        }
        else if (event.type == SDL_MOUSEBUTTONUP) {
            mouseButtonStates_[event.button.button] = false;
        }
        if (event.type == SDL_MOUSEMOTION) {
            mouseX_ = event.motion.x;
            mouseY_ = event.motion.y;
        }
    }
}
bool InputManager::IsKeyPressed(SDL_Scancode key)
{
    return keyStates_[key];
}
bool InputManager::IsKeyReleased(SDL_Scancode key)
{
    return !keyStates_[key];
}
bool InputManager::IsMouseButtonPressed(int button)
{
    return mouseButtonStates_[button];
}
void InputManager::GetMousePosition(int& x, int& y)
{
    x = mouseX_;
    y = mouseY_;
}

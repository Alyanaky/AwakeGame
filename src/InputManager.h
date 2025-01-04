#pragma once
#include <SDL.h>
#include <unordered_map>

enum class InputType {
    KEYBOARD,
    MOUSE
};

class InputManager {
public:
    InputManager();
    ~InputManager();

    void HandleInput();
    bool IsKeyPressed(SDL_Scancode key);
    bool IsKeyReleased(SDL_Scancode key);
    bool IsMouseButtonPressed(int button);
    void GetMousePosition(int& x, int& y);
private:
    std::unordered_map<SDL_Scancode, bool> keyStates_;
    std::unordered_map<int, bool> mouseButtonStates_;
    int mouseX_ = 0;
    int mouseY_ = 0;

};

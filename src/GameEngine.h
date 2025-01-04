#pragma once
#include "Renderer.h"
#include "InputManager.h"
#include "Player.h"

enum class GameState {
    MENU,
    PLAYING,
    PAUSE
};

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    bool Initialize();
    void Run();
    void Update(float deltaTime);
    void Render();

private:
    Renderer* renderer_;
    InputManager* inputManager_;
    Player* player_;
    GameState gameState_ = GameState::MENU;
    bool running_ = false;
};
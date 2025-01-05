#include "GameEngine.h"
#include <iostream>
#include <SDL.h>
#include <chrono>


GameEngine::GameEngine() : renderer_(nullptr), inputManager_(nullptr), player_(nullptr) {
}

GameEngine::~GameEngine() {
    delete renderer_;
    delete inputManager_;
    delete player_;
}

bool GameEngine::Initialize() {
    renderer_ = new Renderer(800, 600);
    if (!renderer_->Initialize()) {
        return false;
    }
    inputManager_ = new InputManager();
    player_ = new Player(50, 50);
    running_ = true;
    return true;
}

void GameEngine::Run() {
    using namespace std::chrono;
    auto lastTime = high_resolution_clock::now();
    while (running_) {
        auto currentTime = high_resolution_clock::now();
        float deltaTime = duration<float, std::milli>(currentTime - lastTime).count() / 1000;
        lastTime = currentTime;

        inputManager_->HandleInput();
        Update(deltaTime);
        Render();
    }
}

void GameEngine::Update(float deltaTime) {
    if (inputManager_->IsKeyPressed(SDL_SCANCODE_ESCAPE)) {
        running_ = false;
        return;
    }
    float moveX = 0.0f;
    float moveY = 0.0f;

    switch (gameState_)
    {
    case GameState::MENU:
        if (inputManager_->IsKeyPressed(SDL_SCANCODE_SPACE)) {
            gameState_ = GameState::PLAYING;
        }
        break;
    case GameState::PLAYING:

        if (inputManager_->IsKeyPressed(SDL_SCANCODE_W)) {
            moveY -= 1;
        }
        if (inputManager_->IsKeyPressed(SDL_SCANCODE_S)) {
            moveY += 1;
        }
        if (inputManager_->IsKeyPressed(SDL_SCANCODE_A)) {
            moveX -= 1;
        }
        if (inputManager_->IsKeyPressed(SDL_SCANCODE_D)) {
            moveX += 1;
        }
        player_->Move(moveX, moveY, deltaTime);
        break;
    case GameState::PAUSE:
        break;
    default:
        break;
    }

}

void GameEngine::Render() {
    renderer_->ClearScreen();
    switch (gameState_) {
    case GameState::MENU:
    {
        SDL_Color color = { 255, 255, 255, 255 };
        renderer_->DrawRect(100, 100, 100, 100, color);
        break;
    }
    case GameState::PLAYING:
        player_->Render(*renderer_);
        break;
    case GameState::PAUSE:

        break;
    default:
        break;
    }
    renderer_->Present();
}
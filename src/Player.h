#pragma once

#include "Renderer.h"

class Player {
public:
	Player(float x, float y);
	~Player();

	void Move(float x, float y, float deltaTime);
	void Render(Renderer& renderer);

private:
	float x_;
	float y_;
	float speed_ = 200;
};
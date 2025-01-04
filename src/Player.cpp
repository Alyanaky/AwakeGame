#include "Player.h"

Player::Player(float x, float y) : x_(x), y_(y) {

}
Player::~Player()
{
}

void Player::Move(float x, float y, float deltaTime)
{
	this->x_ += x * speed_ * deltaTime;
	this->y_ += y * speed_ * deltaTime;
}
void Player::Render(Renderer& renderer)
{
	SDL_Color color = { 255, 255, 255, 255 };
	renderer.DrawRect((int)x_, (int)y_, 30, 30, color);
}
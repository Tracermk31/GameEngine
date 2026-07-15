#include "Player.h"
#include "Input.h"
#include "Engine.h"

using namespace ChiefEngine;

void Player::Update(float dt, float maxX, float maxY) {

    Vector2 force = { 0.0f };
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_A)) { force.x = -m_speed; }
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_D)) { force.x = +m_speed; }
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_W)) { force.y = -m_speed; }
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_S)) { force.y = +m_speed; }

    SetVelocity(GetVelocity() + (force * dt));

    Actor::Update(dt, g_engine.GetRenderer().getWindowWidth(), g_engine.GetRenderer().getWindowHeight());
}

void Player::Draw(const ChiefEngine::Renderer& renderer) const {
	Actor::Draw(renderer);
}
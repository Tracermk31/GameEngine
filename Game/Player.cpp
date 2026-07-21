#include "Player.h"
#include "Input.h"
#include "Engine.h"

using namespace ChiefEngine;

void Player::Update(float dt, float maxX, float maxY) {

    float thrust = 0.0f;
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = +m_speed;
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -m_speed;

    float rotate = 0.0f;
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -180.0f;
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = +180.0f;

    SetRotation(m_transform.rotation + (rotate * dt));

    Vector2 forward{ 1, 0 };
    Vector2 velocity = forward.Rotate(m_transform.rotation * Math::DEGREE_TO_RADIAN)* thrust;
    AddVelocity(velocity * dt);

    Actor::Update(dt, g_engine.GetRenderer().getWindowWidth(), g_engine.GetRenderer().getWindowHeight());
}

void Player::Draw(const ChiefEngine::Renderer& renderer) const {
	Actor::Draw(renderer);
}
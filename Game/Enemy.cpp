#include "Enemy.h"
#include "Player.h"
#include "Engine.h"

using namespace ChiefEngine;

void Enemy::Update(float dt, float maxX, float maxY) {
    Vector2 forward{ 1, 0 };

    //Player* player = m_scene->GetActorByName<Player>("Player");
    //if (player) {
    //    Vector2 direction = player->GetTransform().position - m_transform.position;
    //    float rotation = direction.Angle();
    //    SetRotation(rotation * Math::RADIAN_TO_DEGREE);

    //    Vector2 velocity = forward.Rotate(m_transform.rotation * Math::DEGREE_TO_RADIAN);
    //    AddVelocity(forward * m_speed * dt);
    //}

    Actor::Update(dt, Engine::Get().GetRenderer().getWindowWidth(), Engine::Get().GetRenderer().getWindowHeight());
}

void Enemy::Draw(const ChiefEngine::Renderer& renderer) const {
    Actor::Draw(renderer);
}
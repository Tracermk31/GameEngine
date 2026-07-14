#include "pch.h"
#include "Actor.h"
#include "EngineMath.h"
#include "Renderer.h"

namespace ChiefEngine {
    void Actor::Update(float dt, float maxY, float maxX) {
        m_transform.position += (m_velocity * dt);

        Math::Clamp(0.0f, maxX, m_transform.position.x);
        Math::Clamp(0.0f, maxY, m_transform.position.y);
    }

    void Actor::Draw(const Renderer& renderer) const {
        renderer.DrawModel(m_model, m_transform);
    }
}
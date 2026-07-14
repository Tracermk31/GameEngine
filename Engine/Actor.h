#pragma once

#include "Transform.h"
#include "Model.h"

namespace ChiefEngine {
    class Actor {
    public:
        Actor() = default;
        Actor(const Transform& transform) : m_transform{ transform } {};
        Actor(const Transform& transform, const Model& model) : 
            m_transform{ transform }, 
            m_model{ model } 
        { };

        void Update(float dt, float maxY, float maxX);

        void Draw(const class Renderer& renderer) const;

        inline const Transform& GetTransform() const { return this->m_transform; }
        void SetPosition(const Vector2& position) { m_transform.position = position; }
        void SetRotation(float rotation) { m_transform.rotation = rotation; }
        void SetScale(float scale) { m_transform.scale = scale; }

        inline const Vector2& GetVelocity() const { return m_velocity; }
        void SetVelocity(const Vector2& velocity) { m_velocity = velocity; }
    protected:
        Transform m_transform;
        Vector2 m_velocity = { 0.0f };
        Model m_model;
    };
}
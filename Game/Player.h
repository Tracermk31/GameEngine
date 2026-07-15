#pragma once

#include "Actor.h"

class Player : public ChiefEngine::Actor {
public:
	Player() = default;
	Player(const ChiefEngine::Transform& transform, float speed) :
		Actor{ transform },
		m_speed { speed }
	{}
	Player(const ChiefEngine::Transform& transform, const ChiefEngine::Model& model, float speed) :
		Actor{ transform, model },
		m_speed{ speed }
	{}

	void Update(float dt, float maxX, float maxY) override;
	void Draw (const class ChiefEngine::Renderer& renderer) const override;
private:
	float m_speed = 0.0f;
};
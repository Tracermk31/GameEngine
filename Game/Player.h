#pragma once

#include "Actor.h"

struct PlayerDesc : public ChiefEngine::ActorDesc {
	float speed;
};

class Player : public ChiefEngine::Actor {
public:
	Player() = default;
	Player(PlayerDesc playerDesc) :
		Actor{ playerDesc },
		m_speed { playerDesc.speed }
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
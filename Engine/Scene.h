#pragma once

#include <vector>

namespace ChiefEngine {
	class Actor;

	class Scene {
	private:
		std::vector<Actor*> m_actors;

	public:
		void AddActor(Actor* actor) { m_actors.push_back(actor); }
		void Update(float dt, float maxX, float maxY);
		void Draw(const class Renderer& renderer);

	};
}
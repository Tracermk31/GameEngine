#pragma once

#include "Actor.h"

#include <vector>
#include <string>

namespace ChiefEngine {
	class Scene {
	private:
		std::vector<Actor*> m_actors;
	public:
		void AddActor(Actor* actor);
		template<typename T = Actor>
		inline T* GetActorByName(const std::string& name);
		void Update(float dt, float maxX, float maxY);
		void Draw(const class Renderer& renderer);
	};
}
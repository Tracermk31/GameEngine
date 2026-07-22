#include "pch.h"
#include "Scene.h"
#include "Renderer.h"

namespace ChiefEngine {
	void Scene::AddActor(Actor* actor) {
		actor->m_scene = this;
		m_actors.push_back(actor);
	}

	void Scene::Update(float dt, float maxX, float maxY) {
		for (auto actor : m_actors) {
			actor->Update(dt, maxX, maxY);
		}
	}

	void Scene::Draw(const class Renderer& renderer) {
		for (auto actor : m_actors) {
			actor->Draw(renderer);
		}
	}

	template<typename T>
	inline T* Scene::GetActorByName(const std::string& name) {
		for (auto actor : m_actors) {
			T* tempActor = dynamic_cast<T*>(actor);
			if (tempActor && tempActor->m_name == name) {
				return tempActor;
			}
		}
	}
}
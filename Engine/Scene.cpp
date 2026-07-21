#include "pch.h"
#include "Scene.h"
#include "Actor.h"
#include "Renderer.h"

namespace ChiefEngine {
	void Scene::Update(float dt, float maxX, float maxY) {
		for (Actor* actor : m_actors) {
			actor->Update(dt, maxX, maxY);
		}
	}

	void Scene::Draw(const class Renderer& renderer) {
		for (Actor* actor : m_actors) {
			actor->Draw(renderer);
		}
	}
}
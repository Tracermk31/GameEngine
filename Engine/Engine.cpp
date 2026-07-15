#include "pch.h"
#include "Engine.h"
#include "framework.h"

#include <iostream>

namespace ChiefEngine {
	bool Engine::Initialize() {
		m_renderer.Initialize("Chief Engine", 1920, 1080);
		m_input.Initialize();
		m_time.Reset();
		return true;
	};

	void Engine::Shutdown() {
		m_input.Shutdown();
		m_renderer.ShutDown();
	};

	void Engine::Update() {
		m_input.Update();
		m_time.Tick();
	};
}

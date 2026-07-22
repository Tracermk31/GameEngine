#include "pch.h"
#include "Engine.h"
#include "framework.h"

#include <iostream>

namespace ChiefEngine {
	bool Engine::Initialize(float screenWidth, float screenHeight) {
		m_renderer.Initialize("Chief Engine", (short)screenWidth, (short)screenHeight);
		m_input.Initialize();
		m_time.Reset();
		m_audioSystem.Initialize();
		return true;
	};

	void Engine::Shutdown() {
		m_input.Shutdown();
		m_renderer.ShutDown();
		m_audioSystem.Shutdown();
	};

	void Engine::Update() {
		m_input.Update();
		m_audioSystem.Update();
		m_time.Tick();
	};
}

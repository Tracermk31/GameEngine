#pragma once

#include "pch.h"
#include "Actor.h"
#include "Renderer.h"
#include "Random.h"
#include "Input.h"
#include "EngineTime.h"
#include "EngineMath.h"

#include <vector>
#include <iostream>

namespace ChiefEngine {
	class Engine {
	public:
		Engine() = default;

		bool Initialize();
		void Shutdown();

		void Update();

		Time& GetTime() { return m_time; }
		Input& GetInput() { return m_input; }
		Renderer& GetRenderer() { return m_renderer; }
	private:
		Time m_time;
		Input m_input;
		Renderer m_renderer;
	};

	extern Engine g_engine;
}
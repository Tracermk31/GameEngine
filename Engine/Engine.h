#pragma once

#include "pch.h"
#include "Audio.h"
#include "Actor.h"
#include "Renderer.h"
#include "Random.h"
#include "Input.h"
#include "EngineTime.h"
#include "EngineMath.h"

#include <fmod.hpp>
#include <vector>
#include <iostream>

namespace ChiefEngine {
	class Engine {
	public:
		Engine() = default;

		bool Initialize(float screenWidth, float screenHeight);
		void Shutdown();

		void Update();

		Time& GetTime() { return m_time; }
		Input& GetInput() { return m_input; }
		Renderer& GetRenderer() { return m_renderer; }
		Audio& GetAudio() { return m_audioSystem; }
	private:
		Time m_time;
		Input m_input;
		Renderer m_renderer;
		Audio m_audioSystem;
	};

	extern Engine g_engine;
}
#include "pch.h"
#include "Audio.h" 

namespace ChiefEngine {
	bool Audio::Initialize() {
		FMOD::System_Create(&m_audio);

		void* extradriverdata = nullptr;
		m_audio->init(32, FMOD_INIT_NORMAL, extradriverdata);
		return true;
	}

	void Audio::Shutdown() {
		m_audio->close();
	}

	void Audio::Update() {
		m_audio->update();
	}
}
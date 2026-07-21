#pragma once

#include "pch.h"

#include <vector>
#include <fmod.hpp>

namespace ChiefEngine {
	class Audio {
	private:
		FMOD::System* m_audio;
		std::vector<FMOD::Sound*> m_sounds;
	public:
		bool Initialize();
		void Shutdown();
		void Update();

		FMOD::Sound* GetSoundAtIndex(int index) const {
			return m_sounds.at(index);
		}

		void CreateSound(const char* soundFileToCreate, FMOD::Sound* sound) {
			m_audio->createSound(soundFileToCreate, FMOD_DEFAULT, 0, &sound);
			m_sounds.push_back(sound);
		}

		void CreateSoundAtIndex(const char* soundFileToCreate, FMOD::Sound* sound, int index) {
			CreateSound(soundFileToCreate, sound);
			m_sounds.insert(m_sounds.begin() + index, sound);
		}

		void ClearSounds() {
			m_sounds.clear();
		}

		void PlaySound(FMOD::Sound* sound) const {
			m_audio->playSound(sound, 0, false, nullptr);
		}
	};
}
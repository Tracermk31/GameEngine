#pragma once
#include "Vector2.h"
#include <vector>

namespace ChiefEngine {
	class Input {
	public:
		enum MouseButton {
			LEFT = 1
			, MIDDLE
			, RIGHT
		};

		bool Initialize();
		void Shutdown();
		void Update();

		bool GetKeyDown(int key) const { return m_keyStates[key]; }
		bool GetPrevKeyDown(int key) const { return m_prevKeyStates[key]; }
		bool GetKeyPressed(int key) const { return (m_keyStates[key] && !m_prevKeyStates[key]); }
		bool GetKeyReleased(int key) const { return (!m_keyStates[key] && m_prevKeyStates[key]); }

		bool GetMouseButton(MouseButton button) const { return false; }

		Vector2 GetMousePosition() const { return m_mousePosition; }
	private:
		//Keyboard
		int m_numKeys = 0;
		std::vector<bool> m_keyStates;
		std::vector<bool> m_prevKeyStates;

		//Mouse
		uint32_t m_buttonStates = 0;
		uint32_t m_prevButtonStates = 0;
		Vector2 m_mousePosition{ 0 };
	};
}
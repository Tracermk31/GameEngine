#pragma once
#include <SDL3/SDL.h>

namespace ChiefEngine {
	class Renderer {
		public:
			SDL_Window* GetWindow() {
				return this->m_window;
			}
			SDL_Renderer* GetRenderer() {
				return this->m_renderer;
			}
			bool Initialize(const char* name, short windowWidth, short windowHeight);
			void SetColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);
			void Clear();
			void Present();
			void ShutDown();
			void DrawPoint(float x, float y);
			void DrawFillRect(const SDL_FRect* rectangle);
			void DrawRect(const SDL_FRect* rectangle);
			void DrawLine(float x1, float y1, float x2, float y2);
			void DrawText(float x, float y, const char* string);
		private:
			SDL_Window* m_window = nullptr;
			SDL_Renderer* m_renderer = nullptr;
	};
}
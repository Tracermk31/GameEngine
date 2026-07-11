#pragma once
#include <SDL3/SDL.h>

namespace ChiefEngine {
	class Renderer {
		public:
			inline SDL_Window* GetWindow() { return this->m_window;}
			inline SDL_Renderer* GetRenderer() { return this->m_renderer;}
			bool Initialize(const char* name, short windowWidth, short windowHeight);
			void SetColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255) const;
			void SetColorFloat(float red, float green, float blue, float alpha = 1.0f) const;
			void Clear() const;
			void Present() const;
			void ShutDown() const;
			void DrawPoint(float x, float y) const;
			void DrawFillRect(float x, float y, float w, float h) const;
			void DrawFillRect(const SDL_FRect* rectangle) const;
			void DrawRect(const SDL_FRect* rectangle) const;
			void DrawLine(float x1, float y1, float x2, float y2) const;
			void DrawText(float x, float y, const char* string) const;
		private:
			SDL_Window* m_window = nullptr;
			SDL_Renderer* m_renderer = nullptr;
	};
}
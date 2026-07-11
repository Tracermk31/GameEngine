#include "pch.h"
#include "Renderer.h"
#include <iostream>

namespace ChiefEngine {
    bool Renderer::Initialize(const char* name, short windowWidth, short windowHeight) {
        SDL_Init(SDL_INIT_VIDEO);

        m_window = SDL_CreateWindow(name, windowWidth, windowHeight, 0);
        if (m_window == nullptr) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return false;
        }

        m_renderer = SDL_CreateRenderer(m_window, NULL);
        if (m_renderer == nullptr) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        SDL_SetRenderVSync(m_renderer, -1);

        return true;
    }

    void Renderer::SetColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) const {
        SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
    }

    void Renderer::SetColorFloat(float red, float green, float blue, float alpha) const {
        SDL_SetRenderDrawColorFloat(m_renderer, red, green, blue, alpha);
    }

    void Renderer::Clear() const {
        SDL_RenderClear(m_renderer);
    }

    void Renderer::Present() const {
        SDL_RenderPresent(m_renderer);
    }

    void Renderer::DrawPoint(float x, float y) const {
        SDL_RenderPoint(m_renderer, x, y);
    }

    void Renderer::ShutDown() const {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

    void Renderer::DrawRect(const SDL_FRect* rectangle) const {
        SDL_RenderRect(m_renderer, rectangle);
    }

    void Renderer::DrawFillRect(const SDL_FRect* rectangle) const {
        SDL_RenderFillRect(m_renderer, rectangle);
    }

    void Renderer::DrawFillRect(float x, float y, float w, float h) const {
        SDL_FRect rectangle{ x, y, w, h };
        SDL_RenderFillRect(m_renderer, &rectangle);
    }

    void Renderer::DrawLine(float x1, float y1, float x2, float y2) const {
        SDL_RenderLine(m_renderer, x1, y1, x2, y2);
    }

    void Renderer::DrawText(float x, float y, const char* string) const {
        SDL_RenderDebugText(m_renderer, x, y, string);
    }
}

#include "Engine.h"
#include "SDL3/SDL.h"
#include <iostream>

short SCREEN_WIDTH = 1920;
short SCREEN_HEIGHT = 1080;

int main() {
    ChiefEngine::Renderer renderer;
    renderer.Initialize("ChiefEngine", SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Event e;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        
        SDL_FRect rectangle{
            100, 
            300, 
            rand() % (SCREEN_WIDTH - 100), 
            rand() % (SCREEN_HEIGHT - 300)};

        renderer.SetColor(0, 0, 0); // Set render draw color to black
        renderer.Clear(); // Clear the renderer 

        for (short i = 0; i < 20; i++) {
            renderer.SetColor(rand() % 255, rand() % 255, rand() % 255);
            renderer.DrawPoint(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
            renderer.DrawLine(100, 100, rand() % SCREEN_WIDTH, rand() % 200);
            rectangle.w = rand() % (SCREEN_WIDTH - 100);
            rectangle.h = rand() % (SCREEN_HEIGHT - 300);
            renderer.DrawRect(&rectangle);
        }

        renderer.DrawText(30, 30, "Hello World!");

        renderer.Present(); // Render the screen
    }

    renderer.ShutDown();
    return 0;
}
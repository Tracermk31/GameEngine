#include "Engine.h"

using namespace ChiefEngine;

short SCREEN_WIDTH = 1920;
short SCREEN_HEIGHT = 1080;

int main() {
    // INITIALIZATION
    ChiefEngine::Renderer renderer;
    renderer.Initialize("ChiefEngine", SCREEN_WIDTH, SCREEN_HEIGHT);

    Input input;
    input.Initialize();

    std::vector<Vector2> vector;
    Vector2 vel = Vector2(2, 0);

    for (short i = 0; i < 300; i++) {
        vector.push_back(Vector2{ RandomFloat(SCREEN_WIDTH), RandomFloat(SCREEN_HEIGHT) });
    }

    SDL_FRect rectangle{
        50,
        250,
        RandomFloat(rectangle.x, SCREEN_WIDTH),
        RandomFloat(rectangle.y, SCREEN_HEIGHT)};

    SDL_Event event;

    // MAIN LOOP
    bool running = true;
    while (running) {

        // UPDATE
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.scancode == SDL_SCANCODE_ESCAPE) {
                running = false;
            }
        }

        input.Update();
        if (input.GetKeyDown(SDL_SCANCODE_SPACE)) std::cout << "Down\n";
        //if (input.GetKeyPressed(SDL_SCANCODE_SPACE)) std::cout << "Pressed\n";
        //if (input.GetKeyReleased(SDL_SCANCODE_SPACE)) std::cout << "Released\n";

        // RENDER
        renderer.SetColor(0, 0, 0); // Set render draw color to black
        renderer.Clear(); // Clear the renderer 

        for (size_t index = 0; index < vector.size(); index++) {
            renderer.SetColorFloat(RandomFloat(), RandomFloat(), RandomFloat());
            renderer.DrawPoint(vector[index].x, vector[index].y);
            vector[index] += vel;
            renderer.DrawLine(100, 100, RandomFloat(SCREEN_WIDTH), RandomFloat(200));
            rectangle.w = RandomFloat(SCREEN_WIDTH - rectangle.x);
            rectangle.h = RandomFloat(SCREEN_HEIGHT - rectangle.y);
            renderer.DrawRect(&rectangle);
        }

        renderer.DrawText(input.GetMousePosition().x, input.GetMousePosition().y, "Hello World!");

        renderer.Present(); // Render the screen
    }

    // SHUTDOWN
    renderer.ShutDown();
    return 0;
}
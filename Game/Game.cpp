#include "Engine.h"
#include "Player.h"

using namespace ChiefEngine;

float SCREEN_WIDTH = 1920.0f;
float SCREEN_HEIGHT = 1200.0f;
float SPEED = 1.0f;

int main() {
    // INITIALIZATION
    g_engine.Initialize();

    std::vector<Vector2> points;

    Model playerModel = std::vector<Mesh>{};

    playerModel.AddMesh({ { Vector2{-3, 3,}, Vector2{ 3, 3 }, Vector2{0, 0}} , Color{255.0f, 255.0f, 255.0f} });
    Player player(Transform{ Vector2{ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f }, 0.0f, 50.0f }, playerModel, 800.0f);

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

        g_engine.Update();

        float dt = g_engine.GetTime().getDeltaTime();

        player.SetRotation(player.GetTransform().rotation + (90 * dt));
        player.Update(dt, SCREEN_HEIGHT, SCREEN_WIDTH);

        // INPUT
        if (g_engine.GetInput().GetButtonDown(Input::MouseButton::LEFT)) {
            if (points.empty()) {
                points.push_back(g_engine.GetInput().GetMousePosition());
            }
            else {
                Vector2 temp = points.back() - g_engine.GetInput().GetMousePosition();
                if (temp.Length() > 30.0) {
                    points.push_back(g_engine.GetInput().GetMousePosition());
                }
            }
        }

        if (g_engine.GetInput().GetButtonPressed(Input::MouseButton::RIGHT)) {
            if (!points.empty()) {
                points.pop_back();
            }
        }

        // RENDER
        g_engine.GetRenderer().SetColor(0, 0, 0); // Set render draw color to black
        g_engine.GetRenderer().Clear(); // Clear the renderer 

        for (int index = 0; index < (int)(points.size()) - 1; index++) {
            g_engine.GetRenderer().SetColorFloat(RandomFloat(), RandomFloat(), RandomFloat());
            g_engine.GetRenderer().DrawLine(points[index].x, points[index].y, points[index + 1].x, points[index + 1].y);
        }

        player.Draw(g_engine.GetRenderer());
        g_engine.GetRenderer().Present(); // Render the screen
    }

    // SHUTDOWN
    g_engine.Shutdown();
    return 0;
}
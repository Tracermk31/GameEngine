#include "Engine.h"

using namespace ChiefEngine;

float SCREEN_WIDTH = 1920.0f;
float SCREEN_HEIGHT = 1200.0f;
float SPEED = 1.0f;

int main() {
    // INITIALIZATION
    ChiefEngine::Renderer renderer;
    renderer.Initialize("ChiefEngine", (short)SCREEN_WIDTH, (short)SCREEN_HEIGHT);

    Input input;
    Time time;
    input.Initialize();

    std::vector<Vector2> points;

    Mesh mesh { { Vector2{-3, 3,}, Vector2{ 3, 3 }, Vector2{0, 0}} , Color{255.0f, 255.0f, 255.0f} };
    Model playerModel = std::vector<Mesh>{ mesh };
    Actor player(Transform{ Vector2{ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f }, 0.0f, 50.0f }, playerModel);

    SDL_Event event;

    Vector2 velocity = { 0.0f };
    Vector2 force = { 0.0f };

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
        time.Tick();
        float dt = time.getDeltaTime();

        // INPUT
        if (input.GetButtonDown(Input::MouseButton::LEFT)) {
            if (points.empty()) {
                points.push_back(input.GetMousePosition());
            }
            else {
                Vector2 temp = points.back() - input.GetMousePosition();
                if (temp.Length() > 30.0) {
                    points.push_back(input.GetMousePosition());
                }
            }
        }

        if (input.GetButtonPressed(Input::MouseButton::RIGHT)) {
            if (!points.empty()) {
                points.pop_back();
            }
        }

        if (input.GetKeyDown(SDL_SCANCODE_A)) { force.x = -SPEED; }
        if (input.GetKeyDown(SDL_SCANCODE_D)) { force.x = +SPEED; }
        if (input.GetKeyDown(SDL_SCANCODE_W)) { force.y = -SPEED; }
        if (input.GetKeyDown(SDL_SCANCODE_S)) { force.y = +SPEED; }

        player.SetVelocity(player.GetVelocity() + (force * dt));
        player.Update(dt, renderer.getWindowWidth(), renderer.getWindowHeight());

        // RENDER
        renderer.SetColor(0, 0, 0); // Set render draw color to black
        renderer.Clear(); // Clear the renderer 

        for (int index = 0; index < (int)(points.size()) - 1; index++) {
            renderer.SetColorFloat(RandomFloat(), RandomFloat(), RandomFloat());
            renderer.DrawLine(points[index].x, points[index].y, points[index + 1].x, points[index + 1].y);
        }

        player.Draw(renderer);
        renderer.Present(); // Render the screen
    }

    // SHUTDOWN
    renderer.ShutDown();
    return 0;
}
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"

using namespace ChiefEngine;

float SCREEN_WIDTH = 1920.0f;
float SCREEN_HEIGHT = 1200.0f;

int main() {
    // INITIALIZATION
    g_engine.Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);

    Scene scene;

    std::vector<Vector2> points;

    Model shipModel = std::vector<Mesh>{};

    shipModel.AddMesh({ { Vector2{-1.5f, -1.0f,}, Vector2{ 1.5f, 0.0f }, Vector2{-1.5f, 1.0f}, Vector2{-1.5f, -1.0f} } , Color{255.0f, 255.0f, 255.0f} });
    shipModel.AddMesh({ { Vector2 {-1.5f, -1.0f}, Vector2 {0.0f, -1.0f}, Vector2 {0.0f, -1.5f}, Vector2 {-1.5f, -1.5f}, Vector2 {-1.5f, -1.0f}}, Color{ 0.0f, 0.0f, 200.0f } });
    shipModel.AddMesh({ { Vector2 {-1.5f, 1.0f}, Vector2 {0.0f, 1.0f}, Vector2 {0.0f, 1.5f}, Vector2 {-1.5f, 1.5f}, Vector2 {-1.5f, 1.0f}}, Color{ 0.0f, 0.0f, 200.0f } });

    PlayerDesc playerDesc;
    playerDesc.name = "Player";
    playerDesc.tag = "1";
    playerDesc.speed = 400.0f;
    playerDesc.transform = Transform{ Vector2{ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f }, 0.0f, 50.0f };
    playerDesc.model = shipModel;

    Player* player = new Player(playerDesc);
    scene.AddActor(player);

    for (short index = 0; index < 10; index++) {
        EnemyDesc enemyDesc;
        enemyDesc.name = "Enemy";
        enemyDesc.tag = "2";
        enemyDesc.speed = 400.0f;
        enemyDesc.transform = Transform{ Vector2{ RandomFloat(0, SCREEN_WIDTH), RandomFloat(0, SCREEN_HEIGHT)}, 0.0f, 20.0f };
        enemyDesc.model = shipModel;

        Enemy* enemy = new Enemy(enemyDesc);
        scene.AddActor(enemy);
    }

    SDL_Event event;

    FMOD::Sound* sound = nullptr;

    g_engine.GetAudio().CreateSound("test.wav", sound);
    g_engine.GetAudio().PlaySound(g_engine.GetAudio().GetSoundAtIndex(0));
    g_engine.GetAudio().ClearSounds();

    g_engine.GetAudio().CreateSound("bass.wav", sound);
    g_engine.GetAudio().CreateSound("clap.wav", sound);
    g_engine.GetAudio().CreateSound("close-hat.wav", sound);
    g_engine.GetAudio().CreateSound("cowbell.wav", sound);
    g_engine.GetAudio().CreateSound("open-hat.wav", sound);
    g_engine.GetAudio().CreateSound("snare.wav", sound);
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

        scene.Update(dt, SCREEN_WIDTH, SCREEN_HEIGHT);

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

        if (g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_0)) {
            g_engine.GetAudio().PlaySound(g_engine.GetAudio().GetSoundAtIndex(0));
        }
        if (g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_1)) {
            g_engine.GetAudio().PlaySound(g_engine.GetAudio().GetSoundAtIndex(1));
        }
        if (g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_2)) {
            g_engine.GetAudio().PlaySound(g_engine.GetAudio().GetSoundAtIndex(2));
        }
        if (g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_3)) {
            g_engine.GetAudio().PlaySound(g_engine.GetAudio().GetSoundAtIndex(3));
        }
        if (g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_4)) {
            g_engine.GetAudio().PlaySound(g_engine.GetAudio().GetSoundAtIndex(4));
        }
        if (g_engine.GetInput().GetKeyPressed(SDL_SCANCODE_5)) {
            g_engine.GetAudio().PlaySound(g_engine.GetAudio().GetSoundAtIndex(5));
        }

        // RENDER
        g_engine.GetRenderer().SetColor(0, 0, 0); // Set render draw color to black
        g_engine.GetRenderer().Clear(); // Clear the renderer 

        for (int index = 0; index < (int)(points.size()) - 1; index++) {
            g_engine.GetRenderer().SetColorFloat(RandomFloat(), RandomFloat(), RandomFloat());
            g_engine.GetRenderer().DrawLine(points[index].x, points[index].y, points[index + 1].x, points[index + 1].y);
        }

        scene.Draw(g_engine.GetRenderer());
        g_engine.GetRenderer().Present(); // Render the screen
    }

    // SHUTDOWN
    g_engine.Shutdown();
    return 0;
}
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"

using namespace ChiefEngine;

float SCREEN_WIDTH = 1920.0f;
float SCREEN_HEIGHT = 1200.0f;

int main() {
    // get current working directory
    std::cout << "Directory Operations:\n";
    std::cout << "Working directory: " << GetWorkingDirectory() << "\n";

    // set working directory (current working directory + "Assets")
    std::cout << "Setting directory to 'Assets'...\n";
    SetWorkingDirectory("Assets");
    std::cout << "New directory: " << GetWorkingDirectory() << "\n\n";

    // get filenames in the working directory
    std::cout << "Files in Directory:\n";
    auto filenames = GetFilesInDirectory(GetWorkingDirectory());
    for (const auto& filename : filenames) {
        std::cout << filename << "\n";
    }
    std::cout << "\n";

    // get filename info
    if (!filenames.empty()) {
        // get filename
        std::string str = GetFilename(filenames[0]);
        std::cout << "Filename: " << str << "\n";

        // get extension
        str = GetFileExtension(filenames[0]);
        std::cout << "Extension: " << str << "\n";

        // get filename no extension
        str = GetFilenameNoExtension(filenames[0]);
        std::cout << "Filename No Extension: " << str << "\n\n";
    }

    // read and display text file
    std::cout << "Text File Reading:\n";
    std::string str;
    if (ReadTextFile("test.txt", str)) {
        std::cout << str << "\n";
    }

    // write to text file
    std::cout << "Text File Writing:\n";
    WriteTextFile("test.txt", "Hello, World!", true);
    if (ReadTextFile("test.txt", str)) {
        std::cout << str << "\n";
    }

    // INITIALIZATION
    Engine::Get().Initialize(SCREEN_WIDTH, SCREEN_HEIGHT);

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

    FMOD::Sound* sound = nullptr;

    Engine::Get().GetAudio().CreateSound("test.wav", sound);
    Engine::Get().GetAudio().PlaySound(Engine::Get().GetAudio().GetSoundAtIndex(0));
    Engine::Get().GetAudio().ClearSounds();

    Engine::Get().GetAudio().CreateSound("bass.wav", sound);
    Engine::Get().GetAudio().CreateSound("clap.wav", sound);
    Engine::Get().GetAudio().CreateSound("close-hat.wav", sound);
    Engine::Get().GetAudio().CreateSound("cowbell.wav", sound);
    Engine::Get().GetAudio().CreateSound("open-hat.wav", sound);
    Engine::Get().GetAudio().CreateSound("snare.wav", sound);

    // MAIN LOOP
    SDL_Event event;
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

        float dt = Engine::Get().GetTime().getDeltaTime();

        Engine::Get().Update();

        scene.Update(dt, SCREEN_WIDTH, SCREEN_HEIGHT);

        // INPUT
        if (Engine::Get().GetInput().GetButtonDown(Input::MouseButton::LEFT)) {
            if (points.empty()) {
                points.push_back(Engine::Get().GetInput().GetMousePosition());
            }
            else {
                Vector2 temp = points.back() - Engine::Get().GetInput().GetMousePosition();
                if (temp.Length() > 30.0) {
                    points.push_back(Engine::Get().GetInput().GetMousePosition());
                }
            }
        }

        if (Engine::Get().GetInput().GetButtonPressed(Input::MouseButton::RIGHT)) {
            if (!points.empty()) {
                points.pop_back();
            }
        }

        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_0)) {
            Engine::Get().GetAudio().PlaySound(Engine::Get().GetAudio().GetSoundAtIndex(0));
        }
        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_1)) {
            Engine::Get().GetAudio().PlaySound(Engine::Get().GetAudio().GetSoundAtIndex(1));
        }
        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_2)) {
            Engine::Get().GetAudio().PlaySound(Engine::Get().GetAudio().GetSoundAtIndex(2));
        }
        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_3)) {
            Engine::Get().GetAudio().PlaySound(Engine::Get().GetAudio().GetSoundAtIndex(3));
        }
        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_4)) {
            Engine::Get().GetAudio().PlaySound(Engine::Get().GetAudio().GetSoundAtIndex(4));
        }
        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_5)) {
            Engine::Get().GetAudio().PlaySound(Engine::Get().GetAudio().GetSoundAtIndex(5));
        }

        // RENDER
        Engine::Get().GetRenderer().SetColor(0, 0, 0); // Set render draw color to black
        Engine::Get().GetRenderer().Clear(); // Clear the renderer 

        for (int index = 0; index < (int)(points.size()) - 1; index++) {
            Engine::Get().GetRenderer().SetColorFloat(RandomFloat(), RandomFloat(), RandomFloat());
            Engine::Get().GetRenderer().DrawLine(points[index].x, points[index].y, points[index + 1].x, points[index + 1].y);
        }

        scene.Draw(Engine::Get().GetRenderer());
        Engine::Get().GetRenderer().Present(); // Render the screen
    }

    // SHUTDOWN
    Engine::Get().Shutdown();
    return 0;
}
#include "Engine.h"

using namespace ChiefEngine;

float SCREEN_WIDTH = 1920.0f;
float SCREEN_HEIGHT = 1200.0f;
float SPEED = 0.01;

struct Transform {
    Vector2 position;
    float rotation;
    float scale;
};

class Actor {
public:
    Actor() = default;
    Actor(const Transform& transform) : m_transform{ transform } {};

    void Update(float dt) {
        m_transform.position += (m_velocity * dt);

        Math::Clamp(0.0f, SCREEN_WIDTH, m_transform.position.x);
        Math::Clamp(0.0f, SCREEN_HEIGHT, m_transform.position.y);
    }

    void Draw(const Renderer& renderer) const {
        renderer.SetColor(255, 255, 255);
        renderer.DrawText(m_transform.position.x, m_transform.position.y, "Boo");
    }

    inline const Transform& GetTransform() const { return this->m_transform; }
    void SetPosition(const Vector2& position) { m_transform.position = position; }
    void SetRotation(float rotation) { m_transform.rotation = rotation; }
    void SetScale(float scale) { m_transform.scale = scale; }

    inline const Vector2& GetVelocity() const { return m_velocity; }
    void SetVelocity(const Vector2& velocity) { m_velocity = velocity; }
protected:
    Transform m_transform;
    Vector2 m_velocity = { 0.0f };
};

int main() {
    // INITIALIZATION
    ChiefEngine::Renderer renderer;
    renderer.Initialize("ChiefEngine", (short)SCREEN_WIDTH, (short)SCREEN_HEIGHT);

    Input input;
    Time time;
    input.Initialize();

    Vector2 position{ SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f };

    //Actor player(Transform(position, 0.0f, 50.0f));

    std::vector<Vector2> points;

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

        //if (input.GetKeyDown(SDL_SCANCODE_A)) { force.x = -SPEED; }
        //if (input.GetKeyDown(SDL_SCANCODE_D)) { force.x = +SPEED; }
        //if (input.GetKeyDown(SDL_SCANCODE_W)) { force.y = -SPEED; }
        //if (input.GetKeyDown(SDL_SCANCODE_S)) { force.y = +SPEED; }

        //player.SetVelocity(player.GetVelocity() + (force * dt));
        //player.Update(dt);

        // RENDER
        renderer.SetColor(0, 0, 0); // Set render draw color to black
        renderer.Clear(); // Clear the renderer 

        for (int index = 0; index < (int)(points.size()) - 1; index++) {
            renderer.SetColorFloat(RandomFloat(), RandomFloat(), RandomFloat());
            renderer.DrawLine(points[index].x, points[index].y, points[index + 1].x, points[index + 1].y);
        }

        //player.Draw(renderer);
        renderer.Present(); // Render the screen
    }

    // SHUTDOWN
    renderer.ShutDown();
    return 0;
}
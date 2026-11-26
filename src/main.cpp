#include "raylib.h"
#include "resource_dir.h"
#include "GameController.h"

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    InitWindow(800, 600, "Angry Birds");

    SearchAndSetResourceDir("resources");

    Game_Controller game;

    Camera3D test_camera{};

    test_camera.position = Vector3{ 8.0f, 8.0f, 8.0f };
    test_camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
    test_camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
    test_camera.fovy = 45.0f;
    test_camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose())
    {
        game.processInput();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(game.GetCamera());

        DrawGrid(20, 1.0f);

        DrawCube(
            Vector3{ 0.0f, 1.0f, 0.0f },
            2.0f, 2.0f, 2.0f,
            RED);

        DrawCubeWires(
            Vector3{ 0.0f, 1.0f, 0.0f },
            2.0f, 2.0f, 2.0f,
            BLACK);

        EndMode3D();

        DrawText("TEST CAMERA 3D", 20, 20, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
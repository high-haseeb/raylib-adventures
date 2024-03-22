#include "raylib.h"

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 800;
  InitWindow(screenWidth, screenHeight, "urmom");
  SetTargetFPS(60);

  Camera3D camera = {0};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.position = (Vector3){0.0f, 10.0f, 10.0f};
  camera.fovy = 70;
  camera.projection = CAMERA_PERSPECTIVE;

  Vector3 cubePosition = {0.0f, 0.0f, 0.0f};

  while (!WindowShouldClose()) {
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) UpdateCamera(&camera,CAMERA_FREE);

    BeginDrawing();
    {
      ClearBackground(RAYWHITE);
      {
        BeginMode3D(camera);
        {
          DrawCube(cubePosition, 1.0f, 1.0f, 1.0f, DARKBLUE);
          DrawGrid(10, 1.0f);
        }
        EndMode3D();
      }
      DrawText("i love maham", 10, 10, 10, LIGHTGRAY);
    }
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

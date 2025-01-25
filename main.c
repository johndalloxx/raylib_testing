#include "raylib.h"
#include <math.h>
#include <stdint.h>

typedef enum { CMD_NONE, CMD_MOVE, CMD_ATTACK, CMD_INTERACT } CommandType;

typedef struct Point {
  int32_t x;
  int32_t y;
} Point;

typedef struct Command {
  CommandType type;
  Point target;
} Command;

typedef struct MY_CIRCLE {
  int X;
  int Y;
  float Radius;
  Color Color;
} MY_CIRCLE;

void gravity_on_circle(MY_CIRCLE *circle, int screen_height) {
  if (circle->Y + circle->Radius >= screen_height) {
    return;
  }
  circle->Y += 10;
}

#define MAX_CIRCLES 50

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 800;
  Vector2 drag_start = {.x = 0.0, .y = 0.0};
  bool draggin = false;

  InitWindow(screenWidth, screenHeight, "Raylib - Hello");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    bool left_click_pressed = IsMouseButtonPressed(0);
    bool left_click_down = IsMouseButtonDown(0);

    if (left_click_down && left_click_pressed) {
      drag_start = GetMousePosition();
    }

    if (left_click_down) {
      draggin = true;
    } else {
      draggin = false;
    }
    if (draggin) {
      Vector2 current_mouse_pos = GetMousePosition();
      float width = current_mouse_pos.x - drag_start.x;
      float height = current_mouse_pos.y - drag_start.y;
      Rectangle selectionRect = {
          .x = (width >= 0) ? drag_start.x : drag_start.x + width,
          .y = (height >= 0) ? drag_start.y : drag_start.y + height,
          .width = fabsf(width),
          .height = fabsf(height)};
      DrawRectangleRec(selectionRect, RED);
    }

    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

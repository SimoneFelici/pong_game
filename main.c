#include "raylib.h"

const int screen_width = 800;
const int screen_height= 450;
const int velocity = 500;
const int radius = 20;

void move_ball(float circle_x, float circle_y, float *velocity_x, float *velocity_y)
{
     if ((circle_x >= (screen_width - radius)) || (circle_x <= radius))
     {
         *velocity_x = -*velocity_x;
     }
     if ((circle_y >= (screen_height - radius)) || (circle_y <= radius))
     {
         *velocity_y = -*velocity_y;
     }
}

int main(void)
{
    InitWindow(screen_width, screen_height, "Ping Pong");
    float circle_x = screen_width / 2.0;
    float circle_y = screen_height / 2.0;
    float velocity_x = velocity;
    float velocity_y = velocity;
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle((int)circle_x, (int)circle_y, radius, BLUE);
        EndDrawing();
        circle_x += velocity_x * dt;
        circle_y += velocity_y * dt;
        move_ball(circle_x, circle_y, &velocity_x, &velocity_y);
    }

    CloseWindow();

    return 0;
}

#include "raylib.h"

const int screen_width = 800;
const int screen_height= 450;
const int ball_vel = 500;
const int radius = 20;
const int rect_width = 15;
const int rect_heigth = 100;
const int rect_vel = 500; 

void move_ball(float circle_x, float circle_y, float *ball_vel_x, float *ball_vel_y)
{
     if ((circle_x >= (screen_width - radius)) || (circle_x <= radius))
     {
         *ball_vel_x = -*ball_vel_x;
     }
     if ((circle_y >= (screen_height - radius)) || (circle_y <= radius))
     {
         *ball_vel_y = -*ball_vel_y;
     }
}

int main(void)
{
    InitWindow(screen_width, screen_height, "Ping Pong");
    float circle_x = screen_width / 2.0;
    float circle_y = screen_height / 2.0;
    float ball_vel_x = ball_vel;
    float ball_vel_y = ball_vel;
    float rect_y = screen_height / 2.0;
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle((int)circle_x, (int)circle_y, radius, BLUE);
        DrawRectangle(0, (int)rect_y - (rect_heigth / 2), rect_width, rect_heigth, BLUE);
        DrawRectangle(screen_width - rect_width, (int)rect_y - (rect_heigth / 2), rect_width, rect_heigth, BLUE);
        EndDrawing();
        circle_x += ball_vel_x * dt;
        circle_y += ball_vel_y * dt;
        move_ball(circle_x, circle_y, &ball_vel_x, &ball_vel_y);
    }
    CloseWindow();
    return (0);
}

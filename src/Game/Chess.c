#include "Chess.h"

#include "raylib.h"

void Run() {
    Game game;
    InitWindow(1280, 720, "Chess");
    InitGame(&game);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGREEN);
        DrawBoard(&game);
        EndDrawing();
    }
    CloseWindow();
}

void InitGame(Game *game) {
    game->squareSize = (GetScreenHeight() - 40) / 8.0f;
    for (auto i = 0; i < 8; i++) {
        for (auto j = 0; j < 8; j++) {
            Rectangle r = { .x = i*game->squareSize + 20, .y = j*game->squareSize + 20, .height = game->squareSize, .width = game->squareSize };
            game->board[i][j] = r;
        }
    }
}

void DrawBoard(Game *game) {
    for (auto i = 0; i < 8; i++) {
        for (auto j = 0; j < 8; j++) {
            Color color = (i + j) % 2 == 0 ? LIGHTGRAY : GRAY;
            DrawRectangleRec(game->board[i][j], color);
        }
    }
}
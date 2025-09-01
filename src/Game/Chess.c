#include "Chess.h"

#include "raylib.h"

void Run() {
    Game game;
    InitWindow(1280, 720, "Chess");
    SetTargetFPS(60);
    InitGame(&game);

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGREEN);
        DrawBoard(&game);
        DrawColLabels(&game);
        DrawRowLabels(&game);
        EndDrawing();
    }

    CloseWindow();
}

void InitGame(Game *game) {
    game->squareSize = (GetScreenHeight() - 80) / 8.0f;
    game->font = LoadFontEx(TextFormat("%s/asset/font/Inter/static/Inter_28pt-Regular.ttf", GetWorkingDirectory()), 256, 0, 0);
    for (auto i = 0; i < 8; i++) {
        for (auto j = 0; j < 8; j++) {
            Rectangle r = { .x = i*game->squareSize + 40, .y = j*game->squareSize + 40, .height = game->squareSize, .width = game->squareSize };
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

void DrawRowLabels(Game *game) {
    for (auto j = 0; j < 8; j++) {
        const char *colLabel = TextFormat("%d", -j + 8);
        Vector2 labelSize = MeasureTextEx(game->font, colLabel, 25, 1);
        Vector2 pos = {
            game->board[0][j].x - labelSize.x - 5,
            game->board[0][j].y + game->squareSize / 2 - labelSize.y / 2
        };
        DrawTextEx(game->font, colLabel, pos, 25, 1, BLACK);
    }
}

void DrawColLabels(Game *game) {
    const char *rowLabels = "abcdefgh";
    for (auto i = 0; i < 8; i++) {
        Vector2 pos = {
            game->board[i][7].x + game->squareSize / 2 - MeasureTextEx(game->font, TextFormat("%c", rowLabels[i]), 25, 1).x / 2.0f,
            game->board[i][7].y + game->squareSize
        };
        DrawTextEx(game->font, TextFormat("%c", rowLabels[i]), pos, 25, 1, BLACK);
    }
}
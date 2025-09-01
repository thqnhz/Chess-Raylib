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
        EndDrawing();
    }

    CloseWindow();
}

void InitGame(Game *game) {
    game->squareSize = (GetScreenHeight() - 80) / 8.0f;
    game->font = LoadFontEx(TextFormat("%s/asset/font/Inter/static/Inter_28pt-Regular.ttf", GetWorkingDirectory()), 256, 0, 0);
    for (auto i = 0; i < NUM_SQUARE; i++) {
        for (auto j = 0; j < NUM_SQUARE; j++) {
            Rectangle r = { .x = i*game->squareSize + 40, .y = j*game->squareSize + 40, .height = game->squareSize, .width = game->squareSize };
            game->board[i][j] = r;
        }
    }
}

void DrawBoard(Game *game) {
    const char *rowLabels = "abcdefgh";
    for (auto i = 0; i < NUM_SQUARE; i++) {
        for (auto j = 0; j < NUM_SQUARE; j++) {
            Color color = (i + j) % 2 == 0 ? LIGHTGRAY : GRAY;
            DrawRectangleRec(game->board[i][j], color);
            // Draw row labels
            if (j == 7) {
                DrawRowLabel(game, &game->board[i][j], TextFormat("%c", rowLabels[i]));
            }
            // Draw col labels
            if (i == 0) {
                const char *colLabel = TextFormat("%d", -j + 8);
                DrawColLabel(game, &game->board[i][j], colLabel);
            }
        }
    }
}

void DrawColLabel(Game *game, const Rectangle *r, const char *label) {
    Vector2 labelSize = MeasureTextEx(game->font, label, 25, 1);
    Vector2 pos = {
        .x = r->x - labelSize.x - 5,
        .y = r->y + game->squareSize / 2 - labelSize.y / 2
    };
    DrawTextEx(game->font, label, pos, 25, 1, BLACK);
}

void DrawRowLabel(Game *game, const Rectangle *r, const char *label) {
    Vector2 pos = {
        .x = r->x + game->squareSize / 2 - MeasureTextEx(game->font, TextFormat("%c", label), 25, 1).x / 2.0f,
        .y = r->y + game->squareSize
    };
    DrawTextEx(game->font, label, pos, 25, 1, BLACK);
}
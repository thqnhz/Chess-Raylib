#pragma once

#include "raylib.h"


typedef struct Game {
    float squareSize;
    Rectangle board[8][8];
    Font font;
} Game;

void Run();

void InitGame(Game *game);

void DrawBoard(Game *game);

void DrawColLabels(Game *game);

void DrawRowLabels(Game *game);
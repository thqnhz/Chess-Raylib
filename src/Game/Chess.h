#pragma once

#include "raylib.h"

#define NUM_SQUARE 8

typedef struct Game {
    float squareSize;
    Rectangle board[NUM_SQUARE][NUM_SQUARE];
    Font font;
} Game;

void Run();

void InitGame(Game *game);

void DrawBoard(Game *game);

void DrawRowLabel(Game *game, const Rectangle *r, const char *label);

void DrawColLabel(Game *game, const Rectangle *r, const char *label);
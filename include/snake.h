/*
 * snake.h
 * MSH - Micha1207's snake game.
 *
 * This is a header file for src/snake.c
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Apr 19, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <ncurses.h>

#define STEP_TIME_MS    200
#define SNAKE_LEN_BEGIN 2
#define SNAKE_LEN_MAX   200

typedef struct {
  int y, x;
} Element;

int snake();

#endif

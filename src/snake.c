/*
 * snake.c
 * Snake game logic file.
 *
 * Author:  Micha1207
 * Project: MSG (https:/github.co/Micha1207/MSG)
 * Date:    Apr 17, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
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
} Segment;

/*
 * Snake game logic.
 * Gets input from user, processes it and prints snake.
 * Keys: ([arrow key] or [letter]    direction)
 *        - [UP]      or [W] key     - up
 *        - [DOWN]    or [S] key     - down
 *        - [LEFT]    or [A] key     - left
 *        - [RIGHT]   or [D] key     - right
 *        -              [Q]         - quit qame
 * Returns 0 on success.
 */
int snake(){
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
  clear();
  start_color();
  
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);

  mvprintw(1, 0, "MSG - A simple snake game by github.com/Micha1207");
  mvprintw(3, 2, "Keys:");
  mvprintw(4, 4, "[UP]    or W - up");
  mvprintw(5, 4, "[DOWN]  or S - down");
  mvprintw(6, 4, "[LEFT]  or A - left");
  mvprintw(7, 4, "[RIGHT] or D - right");
  mvprintw(8, 4, "Q            - exit");
  mvprintw(10, 2, "Press any key to play...");
  
  int ch = getch();
  if (ch == 'q' || ch == 'Q'){
    endwin();
    return 0;
  }
  
  timeout(STEP_TIME_MS);
  int term_y = 0, term_x = 0;
  getmaxyx(stdscr, term_y, term_x);

  srand(time(NULL));
  int food_y = 0, food_x = 0;
  food_y = rand() % (term_y - 2);
  if (food_y > term_y) food_y = term_y;
  food_x = rand() % (term_x - 1);

  erase();

  attron(COLOR_PAIR(2));
  mvprintw(food_y, food_x, "#");
  attroff(COLOR_PAIR(2));

  Segment snake[SNAKE_LEN_MAX];
  attron(COLOR_PAIR(3));
  mvprintw(snake[0].y, snake[0].x, "O");
  attroff(COLOR_PAIR(3));

  int score = 0;
  attron(COLOR_PAIR(1));
  mvprintw(term_y - 1, 0, "SCORE: %d | RES: %dx%d | Move: ARROWS or WSAD | Exit: q or Q",
	   score, term_x, term_y);
  attroff(COLOR_PAIR(1));
  refresh();

  char dir = 'r', dir_prev = 'r';
  int snake_length = SNAKE_LEN_BEGIN;
  while (1){
    ch = getch();
    ch = tolower(ch);
    
    if ((ch == KEY_UP || ch == 'w') && dir_prev != 'd')         dir = 'u';
    else if ((ch == KEY_DOWN || ch == 's') && dir_prev != 'u')  dir = 'd';
    else if ((ch == KEY_LEFT || ch == 'a') && dir_prev != 'r')  dir = 'l';
    else if ((ch == KEY_RIGHT || ch == 'd') && dir_prev != 'l') dir = 'r';
    else if (ch == 'q') break;

    for (int i = (snake_length - 1); i > 0; i--){
      snake[i] = snake[i - 1];
    }

    if (dir == 'u')      snake[0].y--;
    else if (dir == 'd') snake[0].y++;
    else if (dir == 'l') snake[0].x--;
    else if (dir == 'r') snake[0].x++;
    
    dir_prev = dir;
    
    if (snake[0].y < 0 || snake[0].y > (term_y - 1) ||
	snake[0].x < 0 || snake[0].x > (term_x - 1)) break;
    
    clear();
    
    getmaxyx(stdscr, term_y, term_x);

    if (snake[0].y == food_y && snake[0].x == food_x){
      food_y = rand() % (term_y - 2);
      food_x = rand() % (term_x - 1);
      score++;
      snake_length++;
    }
    
    attron(COLOR_PAIR(2) | A_BOLD);
    mvprintw(food_y, food_x, "#");
    attroff(COLOR_PAIR(2) | A_BOLD);
    
    for (int i = 1; i < snake_length; i++) {
      if (snake[0].y == snake[i].y && snake[0].x == snake[i].x){
	endwin();
	printf("Game Over! SCORE: %d\n", score);
	return 0;
      }
    }
    
    for (int i = 0; i < snake_length; i++){
      attron(COLOR_PAIR(3) | A_BOLD);
      mvprintw(snake[i].y, snake[i].x, (i == 0) ? "O" : "o");
      attroff(COLOR_PAIR(3) | A_BOLD);
    }
    
    attron(COLOR_PAIR(1));
    mvprintw(term_y - 1, 0, "SCORE: %d | RES: %dx%d | Move: ARROWS or WSAD | Exit: q or Q",
	     score, term_x, term_y);
    attroff(COLOR_PAIR(1));
    
    refresh();
  }

  endwin();
  
  printf("SCORE: %d\n", score);
  
  return 0;
}

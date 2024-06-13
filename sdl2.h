#ifndef SDL2_HEADER
#define SDL2_HEADER
#pragma once
#include <SDL2/SDL.h>
#include "grid.h"
typedef struct SDLContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width;
  int height;
} SDLContext;
/* @brief 
 * Initialise une variable global `context` de type SDLContext
 *
 * Si il y a erreur pendant l'intialisation:
 *  context.window = NULL
 *  ou 
 *  context.renderer = NULL
 *
 * Les deux cas sont à testé !
 * 
 */

/**
 * @brief le type enum represente differents cas, chaque valeur de type enum associe avec un integer constant
 * 
 */
typedef enum Event{
  QUIT, 
  LEFT, 
  RIGHT, 
  UP, 
  DOWN, 
  NON
} Event;

void sdl_init();
/**
 * nettoie la variable global context 
 */
void sdl_quit();
void display_sdl2(struct Grid* grid);
Event event_sdl2();
Event event();
void console_init();
#endif
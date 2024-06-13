#include "sdl2.h"
#include "grid.h"

SDLContext context;

/**
 * @fn void sdl_init
 * @brief Initializes the SDL library for graphical rendering and creates a window
with the specified dimensions.
 * @return void
*/

void sdl_init()
{
  int const width = 1280;
  int const height = 720;
  context = (SDLContext){NULL, NULL, .width = 0, .height = 0};
  if (SDL_Init(SDL_INIT_VIDEO))
  {
    return;
  }

  SDL_Window *window =
      SDL_CreateWindow("Sokoban", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
  if (!window)
  {
    return;
  }
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  context = (SDLContext){
      .window = window, .renderer = renderer, .width = width, .height = height};
}

/**
 * @brief Nettoie et detruit le SDL fenetre et retourne les objects
 * @return void
*/
void sdl_quit()
{
  SDL_DestroyWindow(context.window);
  SDL_DestroyRenderer(context.renderer);
  context.window = NULL;
  context.renderer = NULL;
  SDL_Quit();
}

/**
 * @brief Affiche l'etat courant du jeu grid en utilisant la bibliotheque SDL2 
 * 
 * @param grid Un pointeur vers la structure Grid representat l'etat courant du jeu grid
 *  
 * @return void
 */
void display_sdl2(struct Grid* grid)
{
  float x = 0;
  float y = 0;
  float w = context.width / grid->column_number;
  float h = context.height / grid->row_number;
  SDL_Rect rec;
  SDL_SetRenderDrawColor(context.renderer, 214, 193, 133, 255); 
  SDL_RenderClear(context.renderer);                            
  int index_row, index_column;
  for (index_row = 0; index_row < grid->row_number; index_row++)
  {
    for (index_column = 0; index_column < grid->column_number; index_column++)
    {
      char positionActuelle = grid->game_grid[index_row][index_column];
      switch (positionActuelle)
      {
      case WALL:
      {
        SDL_SetRenderDrawColor(context.renderer, 128, 128, 128, 255);; 
        rec.x = x, rec.y = y, rec.w = w, rec.h = h;
        SDL_RenderFillRect(context.renderer, &rec); 
        break;
      }
      case PLAYER:
      {
        SDL_SetRenderDrawColor(context.renderer, 0, 0, 255, 255); 
        rec.x = x, rec.y = y, rec.w = w, rec.h = h;
        SDL_RenderFillRect(context.renderer, &rec);
        break;
      }
      case GOAL:
      {
        SDL_SetRenderDrawColor(context.renderer, 0, 0, 0, 255); 
        rec.x = x, rec.y = y, rec.w = w, rec.h = h;
        SDL_RenderFillRect(context.renderer, &rec);
        break;
      }
      case BOX:
      {
        SDL_SetRenderDrawColor(context.renderer, 139, 69, 19, 255); 
        rec.x = x, rec.y = y, rec.w = w, rec.h = h;
        SDL_RenderFillRect(context.renderer, &rec);
        break;
      }
      case BOX_ON:
      {
        SDL_SetRenderDrawColor(context.renderer, 0, 128, 0, 255); 
        rec.x = x, rec.y = y, rec.w = w, rec.h = h;
        SDL_RenderFillRect(context.renderer, &rec);
        break;
      }
      case PLAYER_ON:
      {
        SDL_SetRenderDrawColor(context.renderer, 163, 0, 0, 255); 
        rec.x = x, rec.y = y, rec.w = w, rec.h = h;
        SDL_RenderFillRect(context.renderer, &rec);
        break;
      }
      default:
        break;
      }
      x = x + w; 
    }
    y = y + h; 
    x = 0;     
  }
  SDL_RenderPresent(context.renderer); 
}
/**
 * @brief Cela attend pour un evenement de l'utilisateur et retourne une action correspandant Event
 *  
 * @return Un Event enum represantant l'action correspandant a l'Event ou bien 'NON' si cela n'est pas se produit.
 *  
 */
Event event_sdl2()
{
  SDL_Event event;
  Event action = NON;
  SDL_WaitEvent(&event); 
  switch (event.type)
  {
  case SDL_QUIT:
  {
    action = QUIT;
    return action;
    break;
  }
  case SDL_KEYUP: 
  {
    switch (event.key.keysym.sym)
    {
    case SDLK_UP:
    {
      action = UP;
      return action;
      break;
    }
    case SDLK_DOWN:
    {
      action = DOWN;
      return action;
      break;
    }
    case SDLK_RIGHT:
    {
      action = RIGHT;
      return action;
      break;
    }
    case SDLK_LEFT:
    {
      action = LEFT;
      return action;
      break;
    }
    default:
    { 
      action = NON;
      return action;
      break;
    }
    }
  }
  }
  return action;
}

/**
 * @brief Cela attend pour l'Event prochain disponible et renvoie l'action qui correspond.
 * 
 * @return L'action qui corresponde a l'event prochain disponible de l'entree standarde.
 * 
*/
Event event()
{
  Event action;
  char event = fgetc(stdin);// Attend le prochain événement disponible.
  switch (event)
  {
  case 'a':
  {
    action = QUIT;
    return action;
    break;
  }
  case 'z':
  {
    action = UP;
    return action;
    break;
  }
  case 's':
  {
    action = DOWN;
    return action;
    break;
  }
  case 'd':
  {
    action = RIGHT;
    return action;
    break;
  }
  case 'q':
  {
    action = LEFT;
    return action;
    break;
  }
  default:
  {
    action = NON;
    return action;
    break;
  }
  }
}

void console_init()
{
  return ;
}
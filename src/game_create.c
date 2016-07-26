#include <SDL/SDL_image.h>
#include "game.h"
#include "xmalloc.h"

static void	init_textures(t_game *game)
{
  game->background = IMG_Load("data/terrain.png");
  game->texture_blue = IMG_Load("data/blue.png");
  game->texture_red = IMG_Load("data/red.png");
  if (!game->background || !game->texture_blue || !game->texture_red)
    exit(1);
}

static void	init_sdl(t_game *game)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    exit(1);
  if (TTF_Init() == -1)
    exit(1);
  game->font = TTF_OpenFont("data/font.ttf", 32);
  if (!game->font)
    exit(1);
  init_textures(game);
  game->screen = SDL_SetVideoMode(WINDOW_X, WINDOW_Y, 32, WINDOW_OPT);
  if (!game->screen)
    exit(1);
  SDL_WM_SetCaption("Neuf hommes de Morris", NULL);
}

t_game		*game_create()
{
  t_game	*game;

  game = xmalloc(sizeof(t_game));
  init_sdl(game);
  game->field = xmalloc(sizeof(int) * 24);
  game_init(game);
  return (game);
}

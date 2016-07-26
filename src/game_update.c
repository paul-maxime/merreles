#include "game.h"
#include "field.h"
#include "phase.h"

static void	on_click(t_game *game, int idx)
{
  if (game->state == 1)
    phase_one(game, idx);
  else if (game->state == 2)
    phase_two(game, idx);
  else if (game->state != 5)
    phase_del(game, idx);
}

static void	on_keydown(t_game *game, SDLKey key, int *opened)
{
  if (key == SDLK_ESCAPE || key == SDLK_q)
    *opened = 0;
  else if (key == SDLK_r)
    game_init(game);
}

static void	update_mouse(t_game *game, SDL_Event *event)
{
  int		idx;

  if (event->button.button == SDL_BUTTON_LEFT)
    {
      idx = field_get_index(event->button.x, event->button.y);
      if (idx != -1)
	on_click(game, idx);
      else
	game->selected = -1;
    }
}

void		game_update(t_game *game, SDL_Event *event, int *opened)
{
  if (event->type == SDL_QUIT)
    *opened = 0;
  else if (event->type == SDL_KEYDOWN)
    on_keydown(game, event->key.keysym.sym, opened);
  else if (event->type == SDL_MOUSEBUTTONUP)
    update_mouse(game, event);
  game_win(game);
}

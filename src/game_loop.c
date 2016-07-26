#include "game.h"

void		game_loop(t_game *game)
{
  int		opened;
  SDL_Event	event;

  opened = 1;
  while (opened)
    {
      while (SDL_PollEvent(&event))
	game_update(game, &event, &opened);
      game_draw(game);
      game_sleep();
    }
}

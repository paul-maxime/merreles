#include "game.h"

void		game_init(t_game *game)
{
  int		i;

  i = 0;
  while (i < 24)
    game->field[i++] = 0;
  game->player = 1;
  game->state = 1;
  game->placed = 0;
  game->selected = -1;
}

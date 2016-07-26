#include "game.h"

void	phase_del(t_game *game, int idx)
{
  if (game->field[idx] != 0 && game->field[idx] != game->player)
    {
      game->field[idx] = 0;
      game->state -= 2;
      game->player = 3 - game->player;
    }
}

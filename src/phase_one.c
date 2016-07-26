#include "game.h"
#include "field.h"

void	phase_one(t_game *game, int idx)
{
  if (game->field[idx] == 0)
    {
      game->field[idx] = game->player;
      ++game->placed;
      if (game->placed == 18)
	game->state = 2;
      if (field_line(game->field, game->player, idx))
	game->state += 2;
      else
	game->player = 3 - game->player;
    }
}

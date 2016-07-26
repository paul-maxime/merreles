#include "game.h"
#include "field.h"

void	phase_two(t_game *game, int idx)
{
  if (game->selected == -1)
    {
      if (game->field[idx] == game->player)
	game->selected = idx;
    }
  else
    {
      if (game->field[idx] == 0)
	{
	  if (field_move(game->field, game->player, game->selected, idx))
	    {
	      game->field[idx] = game->player;
	      game->field[game->selected] = 0;
	      if (field_line(game->field, game->player, idx))
		game->state = 4;
	      else
		game->player = 3 - game->player;
	    }
	}
	game->selected = -1;
    }
}

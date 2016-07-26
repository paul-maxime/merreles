#include "game.h"
#include "field.h"

static int	is_loser(t_game *game)
{
  if (field_count(game->field, game->player) < 3)
    return (1);
  if (!field_can_move(game->field, game->player))
    return (1);
  return (0);
}

void		game_win(t_game *game)
{
  if (game->state == 2)
    {
      if (is_loser(game))
	{
	  game->player = 3 - game->player;
	  game->state = 5;
	}
    }
}

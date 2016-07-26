#include "game.h"

int		main()
{
  t_game	*game;

  game = game_create();
  game_loop(game);
  game_quit(game);
  return (0);
}

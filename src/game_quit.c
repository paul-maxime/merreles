#include "game.h"

void	game_quit(t_game *game)
{
  SDL_FreeSurface(game->texture_blue);
  SDL_FreeSurface(game->texture_red);
  SDL_FreeSurface(game->background);
  TTF_CloseFont(game->font);
  free(game->field);
  free(game);
  TTF_Quit();
  SDL_Quit();
}

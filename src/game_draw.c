#include "game.h"
#include "field.h"

static void	draw_moved_play(t_game *game)
{
  SDL_Rect	rect;
  int		x;
  int		y;

  SDL_GetMouseState(&x, &y);
  rect.x = x - IMG_SIZE;
  rect.y = y - IMG_SIZE;
  if (game->player == 1)
    SDL_BlitSurface(game->texture_blue, NULL, game->screen, &rect);
  else
    SDL_BlitSurface(game->texture_red, NULL, game->screen, &rect);
}

static void	draw_field(t_game *game)
{
  SDL_Rect	rect;
  int		i;

  i = 0;
  while (i < 24)
    {
      if (game->field[i] > 0 && game->selected != i)
	{
	  field_get_coords(i, &rect);
	  if (game->field[i] == 1)
	    SDL_BlitSurface(game->texture_blue, NULL, game->screen, &rect);
	  else
	    SDL_BlitSurface(game->texture_red, NULL, game->screen, &rect);
	}
      ++i;
    }
}

static void	print_text(t_game *game, char *str, int x, int y)
{
  SDL_Surface	*text;
  SDL_Rect	rect;
  SDL_Color	color;

  color.r = 0;
  color.g = 0;
  color.b = 0;
  rect.x = x;
  rect.y = y;
  text = TTF_RenderText_Solid(game->font, str, color);
  SDL_BlitSurface(text, NULL, game->screen, &rect);
  SDL_FreeSurface(text);
}

static void	draw_text(t_game *game)
{
  if (game->player == 1)
    print_text(game, "Joueur 1", 100, 50);
  else
    print_text(game, "Joueur 2", 100, 50);
  if (game->state == 1)
    print_text(game, "Placez un pion", 600, 50);
  else if (game->state == 2)
    print_text(game, "Deplacez un pion", 600, 50);
  else if (game->state != 5)
    print_text(game, "Enlevez un pion", 600, 50);
  else
    print_text(game, "Partie terminee !", 600, 50);
}

void		game_draw(t_game *game)
{
  SDL_Rect	rect;

  rect.x = 0;
  rect.y = 0;
  SDL_BlitSurface(game->background, NULL, game->screen, &rect);
  draw_field(game);
  draw_text(game);
  if (game->selected >= 0)
    draw_moved_play(game);
  SDL_Flip(game->screen);
}

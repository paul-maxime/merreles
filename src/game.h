#ifndef GAME_H_
# define GAME_H_

# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>

# define WINDOW_X 1024
# define WINDOW_Y 768
# define WINDOW_OPT SDL_HWSURFACE | SDL_DOUBLEBUF
# define FRAME_DELAY 20

typedef struct	s_game
{
  SDL_Surface	*screen;
  SDL_Surface	*background;
  SDL_Surface	*texture_blue;
  SDL_Surface	*texture_red;
  TTF_Font	*font;
  int		*field;
  int		player;
  int		state;
  int		placed;
  int		selected;
}		t_game;

/* Initializes the game resources and the SDL library */
t_game	*game_create();

/* Initializes game variables */
void	game_init(t_game *game);

/* Main window loop */
void	game_loop(t_game *game);

/* Updates the game based on the events */
void	game_update(t_game *game, SDL_Event *event, int *opened);

/* Draws the game on the screen */
void	game_draw(t_game *game);

/* Checks if there is a winner */
void	game_win(t_game *game);

/* Waits until the end of the frame */
void	game_sleep();

/* Frees the resources used by the game */
void	game_quit(t_game *game);

#endif /* !GAME_H_ */

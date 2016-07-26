#ifndef FIELD_H_
# define FIELD_H_

# include <SDL/SDL.h>

# define IMG_SIZE 32

/* Retrieves the cell index corresponding to the specified coordinates */
int	field_get_index(int x, int y);

/* Stores the specified cell into a SDL rectangle */
void	field_get_coords(int idx, SDL_Rect *rect);

/* Retrieves the amount of pieces placed on the board */
int	field_count(int *field, int player);

/* Returns true if the specified piece forms a line */
int	field_line(int *field, int player, int idx);

/* Returns true if the specified piece can move to the specified location */
int	field_move(int *field, int player, int idx_from, int idx_to);

/* Returns true if the specified player can move another piece. */
int	field_can_move(int *field, int player);

#endif /* !FIELD_H_ */

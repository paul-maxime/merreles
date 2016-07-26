#include "field.h"

static const int	field_coords[48] =
  {
    45, 36,
    515, 36,
    985, 36,
    199, 151,
    511, 149,
    827, 153,
    356, 268,
    515, 267,
    671, 271,
    40, 386,
    205, 389,
    356, 389,
    671, 383,
    827, 391,
    982, 388,
    358, 503,
    515, 506,
    668, 504,
    211, 621,
    515, 623,
    828, 619,
    44, 732,
    514, 732,
    983, 732
  };

int	field_get_index(int x, int y)
{
  int	i;

  i = 0;
  while (i < 24)
    {
      if (x > field_coords[i * 2] - IMG_SIZE &&
	  x < field_coords[i * 2] + IMG_SIZE &&
	  y > field_coords[i * 2 + 1] - IMG_SIZE &&
	  y < field_coords[i * 2 + 1] + IMG_SIZE)
	return (i);
      ++i;
    }
  return (-1);
}

void	field_get_coords(int idx, SDL_Rect *rect)
{
  rect->x = field_coords[idx * 2] - IMG_SIZE;
  rect->y = field_coords[idx * 2 + 1] - IMG_SIZE;
}

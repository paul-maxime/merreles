#include "field.h"

static const int	field_moves[96] =
  {
    1, 9, -1, -1,
    0, 2, 4, -1,
    1, 14, -1, -1,
    4, 10, -1, -1,
    1, 3, 5, 7,
    4, 13, -1, -1,
    7, 11, -1, -1,
    4, 6, 8, -1,
    7, 12, -1, -1,
    0, 10, 21, -1,
    3, 9, 11, 18,
    6, 10, 15, -1,
    8, 13, 17, -1,
    5, 12, 14, 20,
    2, 13, 23, -1,
    11, 16, -1, -1,
    15, 17, 19, -1,
    12, 16, -1, -1,
    10, 19, -1, -1,
    16, 18, 20, 22,
    13, 19, -1, -1,
    9, 22, -1, -1,
    19, 21, 23, -1,
    14, 22, -1, -1
  };

int	field_move(int *field, int player, int idx_from, int idx_to)
{
  int	i;

  if (field_count(field, player) == 3)
    return (1);
  i = 0;
  while (i < 4)
    {
      if (field_moves[idx_from * 4 + i] == idx_to)
	return (1);
      ++i;
    }
  return (0);
}

int	field_can_move(int *field, int player)
{
  int	idx;
  int	i;

  idx = 0;
  while (idx < 24)
    {
      if (field[idx] == player)
	{
	  i = 0;
	  while (i < 4)
	    {
	      if (field_moves[idx * 4 + i] >= 0 &&
		  field[field_moves[idx * 4 + i]] == 0)
		return (1);
	      ++i;
	    }
	}
      ++idx;
    }
  return (0);
}

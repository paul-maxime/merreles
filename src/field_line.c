static const int	field_lines[96] =
  {
    1, 2, 9, 21,
    0, 2, 4, 7,
    0, 1, 14, 23,
    4, 5, 10, 18,
    3, 5, 1, 7,
    3, 4, 13, 20,
    7, 8, 11, 15,
    6, 8, 4, 1,
    6, 7, 12, 17,
    10, 11, 0, 21,
    9, 11, 3, 18,
    9, 10, 6, 15,
    8, 17, 13, 14,
    12, 14, 5, 20,
    12, 13, 2, 23,
    6, 11, 16, 17,
    15, 17, 19, 22,
    8, 12, 15, 16,
    3, 10, 19, 20,
    18, 20, 16, 22,
    18, 19, 5, 13,
    0, 9, 22, 23,
    21, 23, 16, 19,
    21, 22, 2, 14
  };

int	field_line(int *field, int player, int idx)
{
  int	pos1;
  int	pos2;

  pos1 = field_lines[idx * 4];
  pos2 = field_lines[idx * 4 + 1];
  if (field[pos1] == player && field[pos2] == player)
    return (1);
  pos1 = field_lines[idx * 4 + 2];
  pos2 = field_lines[idx * 4 + 3];
  if (field[pos1] == player && field[pos2] == player)
    return (1);
  return (0);
}

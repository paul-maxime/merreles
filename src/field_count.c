int	field_count(int *field, int player)
{
  int	count;
  int	i;

  count = 0;
  i = 0;
  while (i < 24)
    {
      if (field[i] == player)
	++count;
      ++i;
    }
  return (count);
}

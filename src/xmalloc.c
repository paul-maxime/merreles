#include <stdlib.h>

void	*xmalloc(unsigned int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (!ptr)
    exit(2);
  return (ptr);
}

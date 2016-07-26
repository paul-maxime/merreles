#include "game.h"

void		game_sleep()
{
  static Uint32 next_draw;
  Uint32	now;

  now = SDL_GetTicks();
  if (next_draw <= now)
    next_draw = now + FRAME_DELAY;
  else
    SDL_Delay(next_draw - now);
}

#include "lib.h"

t_bunny_response event_handler(t_bunny_event_state state, t_bunny_keysym key, __attribute__((unused))void *data)
{   
  return state == GO_DOWN && key == BKS_ESCAPE ? EXIT_ON_SUCCESS : GO_ON;
}

t_bunny_response __loop (void *data)
{
  (void) data;
  return GO_ON;
}

t_bunny_response __display(void *data)
{
  Panda* d = (Panda *)data;
  d->clear(COLOR(40, 0, 0, 0));
  if (d->l < 25 && d->end == true)
    {
      d->l++;
      if (d->l == 25)
	d->end = false;
    }
  else
    {
      d->l--;
      if (d->l == 1)
	d->end = true;
    }
  t_bunny_position p[4];
  p[0] = {50, 50};
  p[1] = {d->getWidth() - 50, 50};
  p[2] = {d->getWidth() - 50, d->getHeight() - 50};
  p[3] = {50, d->getHeight() - 50};
  //  d->whirlpool(p, 0.1, d->l, COLOR(10, 128, 128, 128));
  d->whirlpool_alpha(p, 0.1, d->l, COLOR(255, rand()%255, rand()%255, rand()%255));
  bunny_blit (&d->_win->buffer, &d->_px->clipable, NULL);
  bunny_display(d->_win);
  return GO_ON;
}


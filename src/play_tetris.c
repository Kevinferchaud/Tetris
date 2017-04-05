/*
** play_tetris.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 20:40:06 2017 ferchaud kevin
** Last update Sat Mar 18 20:40:35 2017 ferchaud kevin
*/

#include "my.h"

int             check_level(int k, t_plat **game, t_data *data)
{
  if (k == (11 - data->l))
    {
      k = 0;
      if (stock_tetribuffer((*game)->tetri[(*game)->c], game) == 0)
	{
	  (*game)->c = (*game)->c2;
	  (*game)->c2 = rand() % (*game)->nbtetri;
	}
      else
	(*game)->y++;
    }
  return (k);
}

void                    play_tetrisless(t_plat *game, char *buffer,
					char **touch, t_data *data)
{
  char                  *tmp;
  int                   i;
  int                   k;
  double                timepast;

  tmp = init_tetrirand(&game);
  k = 0;
  while (1)
    {
      clear();
      timepast = clock();
      print_map(game, data);
      i = read(0, buffer, 100);
      buffer[i] = '\0';
      if (i > 0)
	tmp = check_buffer(buffer, tmp, touch, &game);
      k = check_level(k, &game, data);
      print_play(&game, &data, timepast);
      k++;
    }
}

/*
** init3.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 17:09:50 2017 Maxime Le Huu Nho
** Last update Sun Mar 19 17:22:20 2017 ferchaud kevin
*/

#include "my.h"

t_plat			*init_platless(t_plat *res, t_data *data,
				       t_list *infos, char **game)
{
  res->game = game;
  res->x = 41 + (data->mapsize[1] / 2);
  res->y = 1;
  res->mapsize[0] = data->mapsize[0];
  res->mapsize[1] = data->mapsize[1];
  res->score = 0;
  res->highscore = readmyscore();
  res->line = 0;
  return (res);
}

t_plat			*init_plat(t_data *data, t_list *infos)
{
  t_plat		*res;
  char			**game;
  int			i;
  int			j;

  if ((res = malloc(sizeof(t_plat))) == NULL)
    exit(84);
  if ((game = malloc((data->mapsize[0] + 1) * sizeof(char *))) == NULL)
    exit(84);
  res->tetri = init_mlist(infos);
  i = 0;
  while (i < data->mapsize[0])
    {
      j = 0;
      if ((game[i] = malloc((data->mapsize[1] + 1) * sizeof(char *))) == NULL)
	exit(84);
      while (j < data->mapsize[1])
	game[i][j++] = ' ';
      game[i][j] = '\0';
      i++;
    }
  game[i] = NULL;
  return (init_platless(res, data, infos, game));
}

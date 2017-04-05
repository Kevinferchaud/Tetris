/*
** check.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 17:27:04 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 21:06:01 2017 ferchaud kevin
*/

#include "my.h"

void			check_args(char **av, char **cmds, char **cmdl)
{
  int			i;
  int			j;

  i = 1;
  while (av[i])
    if (my_strcmpamoi("--help", av[i++]) == 1)
      my_usage(av, 0);
}

int			*check_cmd(char *av, char **cmdl, char **cmds)
{
  int			i;
  int			*res;

  if ((res = malloc(2 * sizeof(int))) == NULL)
    exit(84);
  i = -1;
  while (cmdl[++i])
    if (my_strcmpamoi(cmdl[i], av) == 1)
      {
	res[0] = 0;
	res[1] = i;
	return (res);
      }
  i = -1;
  while (cmds[++i])
    if (my_strcmpamoi2(av, cmds[i]) == 1)
      {
	res[0] = 1;
	res[1] = i;
	return (res);
      }
  res[0] = -1;
  res[1] = -1;
  return (res);
}

t_data			*check_margument(char **cmds, t_data *data,
					 char **cmdl, char **av)
{
  int			i;
  int			j;
  t_args		*args;
  int			*res;

  args = init_args();
  i = 1;
  while (av[i] != NULL)
    {
      res = check_cmd(av[i], cmdl, cmds);
      if (res[0] == 0)
	data = args[res[1]](recup_av(av[i]), data);
      else
	if ((res[1] == 7 || res[1] == 8) && res[0] == 1)
	  data = args[res[1]](av[i], data);
	else
	  if (res[0] == 1)
	    data = args[res[1]](av[++i], data);
	  else
	    my_usage(av, 1);
      if (av[i] != NULL)
	i++;
    }
  return (data);
}

void			check_touch(char **touch, char **av)
{
  int			i;
  int			j;

  i = 0;
  while (touch[i])
    {
      j = i;
      while (touch[++j])
	if (my_strcmpamoi2(touch[i], touch[j]) == 1)
	  my_usage(av, 1);
      i++;
    }
}

char			*check_buffer(char *buffer, char *tmp, char **touch,
				      t_plat **game)
{
  int			i;
  int			c;
  t_touch		*touche;

  i = 0;
  c = 0;
  tmp = strcatamoi(tmp, buffer);
  touche = init_touch();
  while (touch[i])
    if (my_strncmpmoi(tmp, touch[i++], my_strlen(tmp) - 1) == 0)
      c = 1;
  if (c == 0)
    {
      tmp[0] = '\0';
      return (tmp);
    }
  i = -1;
  while (touch[++i])
    if (my_strcmpamoi2(tmp, touch[i]) == 1)
      {
	touche[i](game, (*game)->tetri[(*game)->c], touch);
	tmp[0] = '\0';
	return (tmp);
      }
  return (tmp);
}

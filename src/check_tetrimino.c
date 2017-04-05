/*
** check_tetrimino.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:28:50 2017 ferchaud kevin
** Last update Sun Mar 19 16:12:13 2017 ferchaud kevin
*/

#include "my.h"

cpt_list        *changecpts(cpt_list *st, char *str)
{
  st->cpt3++;
  st->cpt2 = 0;
  if (str[st->cpt] == ' ')
    st->cpt++;
  while (str[st->cpt] >= '0' && str[st->cpt] <= '9')
    {
      st->cpt2++;
      st->cpt++;
    }
  if ((st->ints[st->cpt3] = malloc(sizeof(char) * (st->cpt2 + 1))) == NULL)
    exit(84);
  st->cpt = st->cpt - st->cpt2;
  st->cpt4 = 0;
  return (st);
}

int		checkextension(char *name)
{
  char		*str;
  int		cpt;
  int		cpt2;
  int		cpt3;

  cpt = -1;
  cpt2 = -1;
  cpt3 = 0;
  while (name[++cpt] != '\0')
    if (name[cpt] == '.')
      {
	while (name[++cpt] != '\0')
	  cpt3++;
	if ((str = malloc(sizeof(char) * (cpt3 + 1))) == NULL)
	  exit(84);
	cpt -= (cpt3 + 1);
	while (name[++cpt] != '\0')
	  str[++cpt2] = name[cpt];
	str[++cpt2] = '\0';
	if (my_strcmpamoi2(str, "tetrimino") == 1)
	  return (1);
      }
  return (0);
}

int		check_valinf(char *all)
{
  int		cpt;
  int		test;

  cpt = 0;
  test = 0;
  while (all[cpt] != '\0' && test == 0)
    {
      while (all[cpt] != '\n')
	cpt++;
      while (all[++cpt] != '\0' && test == 0)
	if (all[cpt] != ' ' &&
	    all[cpt] != '*' && all[cpt] != '\n')
	  return (1);
    }
  return (0);
}

int		checkn(char *name)
{
  char		*newname;
  char		*all;
  int		cpt;
  int		fd;
  char		*buf;
  int		i;

  all = NULL;
  if ((buf = malloc(sizeof(char) * 2)) == NULL)
    exit(84);
  newname = strcatamoi("tetriminos/", name);
  cpt = 0;
  if ((fd = open(newname, O_RDONLY)) == -1)
    exit (84);
  while ((i = read(fd, buf, 1)) > 0)
    {
      buf[i] = '\0';
      cpt++;
      all = strcatamoi(all, buf);
    }
  close(fd);
  if (all[my_strlen(all) - 1] != '\n' ||
      check_valinf(all) == 1)
    return (1);
  return (0);
}

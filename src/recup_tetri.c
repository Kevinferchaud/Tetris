/*
** recup_tetri.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:43:13 2017 ferchaud kevin
** Last update Sun Mar 19 17:32:36 2017 ferchaud kevin
*/

#include "my.h"

char            **recuptetri(char *tetri, t_list *infos, int val)
{
  char          **res;
  int           cpt;
  int           cpt2;
  int           cpt3;

  cpt = -1;
  cpt3 = 0;
  if ((res = malloc(sizeof(char *) * (gnb2(infos->size[val]) + 1))) == NULL)
    exit(84);
  while (++cpt < gnb2(infos->size[val]))
    {
      if ((res[cpt] = malloc(sizeof(char) * my_strlen(tetri))) == NULL)
	exit(84);
      cpt2 = 0;
      while (tetri[cpt3] != '\n' && tetri[cpt3] != '\0')
	res[cpt][cpt2++] = tetri[cpt3++];
      res[cpt][cpt2] = '\0';
      cpt3++;
    }
  res[cpt] = NULL;
  return (res);
}

char            **recupint(char *str)
{
  cpt_list      *st;
  int           fd;

  st = init_cpts();
  while (str[st->cpt] != '\n')
    {
      if ((checkforerror(str, st->cpt)) == 1)
	{
	  st = send_error(st);
	  return (st->ints);
	}
      st = changecpts(st, str);
      while (str[st->cpt] >= '0' && str[st->cpt] <= '9')
	st->ints[st->cpt3][st->cpt4++] = str[st->cpt++];
      st->ints[st->cpt3][st->cpt4] = '\0';
    }
  if (st->cpt3 != 2)
    {
      st = send_error(st);
      return (st->ints);
    }
  st->ints[3] = NULL;
  return (st->ints);
}


/*
** annexe.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:37:35 2017 ferchaud kevin
** Last update Sun Mar 19 17:15:14 2017 ferchaud kevin
*/

#include "my.h"

int             gnb1(char *str)
{
  int           cpt;
  int           res;

  cpt = -1;
  res = 0;
  while (str[++cpt] != '*' && str[cpt] != '\0')
    res = res * 10 + (str[cpt] - '0');
  return (res);
}

int             gnb2(char *str)
{
  int           cpt;
  int           res;

  cpt = -1;
  res = 0;
  while (str[++cpt] != '*' && str[cpt] != '\0');
  if (str[cpt] != '\0')
    while (str[++cpt] != '\0')
      res = res * 10 + (str[cpt] - '0');
  return (res);
}

t_list          *swap_infos(t_list *infos, int cpt)
{
  char          *swap;

  swap = infos->name[cpt];
  infos->name[cpt] = infos->name[cpt + 1];
  infos->name[cpt + 1] = swap;
  swap = infos->size[cpt];
  infos->size[cpt] = infos->size[cpt + 1];
  infos->size[cpt + 1] = swap;
  swap = infos->color[cpt];
  infos->color[cpt] = infos->color[cpt + 1];
  infos->color[cpt + 1] = swap;
  swap = infos->tetri[cpt];
  infos->tetri[cpt] = infos->tetri[cpt + 1];
  infos->tetri[cpt + 1] = swap;
  return (infos);
}

char    *my_getchar(int number)
{
  int   cpt;
  int   cpt2;
  char  *str;
  int   tot;

  if (number == 0)
    return ("0");
  cpt = 0;
  tot = number;
  while (number > 9)
    {
      number /= 10;
      cpt++;
    }
  if ((str = malloc(sizeof(char) * (cpt + 1))) == NULL)
    exit(84);
  cpt = 0;
  while (tot > 0)
    {
      str[cpt++] = tot % 10 + '0';
      tot /= 10;
    }
  str[cpt] = '\0';
  return (my_revstr(str));
}

char    *my_revstr(char *str)
{
  char  *res;
  int   cpt;
  int   cpt2;

  if ((res = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(84);
  cpt = my_strlen(str);
  cpt2 = -1;
  while (--cpt >= 0)
    res[++cpt2] = str[cpt];
  res[++cpt2] = '\0';
  return (res);
}

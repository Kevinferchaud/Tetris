/*
** check_tetrierror.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:28:04 2017 ferchaud kevin
** Last update Sat Mar 18 16:30:37 2017 ferchaud kevin
*/

#include "my.h"

int     iserror(char *str)
{
  if (str[0] == 'e' &&
      str[1] == 'r' &&
      str[2] == 'r' &&
      str[3] == 'o' &&
      str[4] == 'r')
    return (1);
  return (0);
}

t_list          *list_error(t_list *infos, int cpt)
{
  infos->size[cpt] = my_strdup("error");
  infos->color[cpt] = my_strdup("error");
  infos->tetri[cpt] = my_strdup("error");
  return (infos);
}

int     checkforerror(char *str, int cpt)
{
  if (str[cpt] == '\0' ||
      (str[cpt] != '\n' && str[cpt] != ' ' &&
       (str[cpt] < '0' || str[cpt] > '9')))
    return (1);
  return (0);
}

cpt_list        *send_error(cpt_list *st)
{
  st->ints[0] = my_strdup("error");
  st->ints[1] = my_strdup("error");
  st->ints[2] = my_strdup("error");
  return (st);
}

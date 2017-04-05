/*
** init_list.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:35:38 2017 ferchaud kevin
** Last update Sat Mar 18 21:38:45 2017 ferchaud kevin
*/

#include "my.h"

t_list          *malloc_list(t_list *infos, int cpt)
{
  if ((infos->name = malloc(sizeof(char *) * (cpt + 1))) == NULL)
    exit(84);
  if ((infos->size = malloc(sizeof(char *) * (cpt + 1))) == NULL)
    exit(84);
  if ((infos->recupval = malloc(sizeof(char *) * (cpt + 1))) == NULL)
    exit(84);
  if ((infos->color = malloc(sizeof(char *) * (cpt + 1))) == NULL)
    exit(84);
  if ((infos->tetri = malloc(sizeof(char *) * (cpt + 1))) == NULL)
    exit(84);
  return (infos);
}

t_list          *null_list(t_list *infos, int cpt)
{
  infos->name[cpt] = NULL;
  infos->size[cpt] = NULL;
  infos->tetri[cpt] = NULL;
  infos->color[cpt] = NULL;
  return (infos);
}

t_list          *modif_list(t_list *infos, int cpt,
			    struct stat sb, char *name)
{
  infos->size[cpt] = parsesize(infos->recupval[0], infos->recupval[1]);
  infos->color[cpt] = infos->recupval[2];
  if (my_getnbr(infos->color[cpt]) < 1 ||
      my_getnbr(infos->color[cpt]) > 7)
    infos = list_error(infos, cpt);
  infos->tetri[cpt] = parsetetri(name, sb.st_size, 0);
  return (infos);
}

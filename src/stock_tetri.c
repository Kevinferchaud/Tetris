/*
** stock_tetri.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:34:55 2017 ferchaud kevin
** Last update Sat Mar 18 16:35:08 2017 ferchaud kevin
*/

#include "my.h"

int                     count_tetri()
{
  int                   i;
  DIR                   *dir;
  struct dirent         *open;

  i = 0;
  if ((dir = opendir("tetriminos")) == NULL)
    exit(84);
  while ((open = readdir(dir)) != NULL)
    if (my_strcmpamoi2(open->d_name, ".") != 1 &&
	my_strcmpamoi2(open->d_name, "..") != 1 &&
	checkextension(open->d_name) == 1)
      i++;
  closedir(dir);
  return (i);
}

t_list                  *stock_tetri()
{
  t_list                *infos;
  struct stat           sb;
  DIR                   *dir;

  if ((infos = malloc(sizeof(t_list))) == NULL)
    exit(84);
  infos = malloc_list(infos, count_tetri());
  if ((dir = opendir("tetriminos")) == NULL)
    exit(84);
  infos = make_list(infos, dir, sb, 0);
  infos = null_list(infos, infos->nbtetri);
  infos = print_tetri(infos);
  return (infos);
}

/*
** make_list.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:34:05 2017 ferchaud kevin
** Last update Sun Mar 19 16:19:20 2017 ferchaud kevin
*/

#include "my.h"

t_list          *make_listless(t_list *infos, int count, int cpt)
{
  if (count == 0)
    exit(84);
  infos->nbtetri = cpt;
  return (infos);
}

t_list          *make_list(t_list *infos, DIR *dir,
			   struct stat sb, int count)
{
  int           cpt;
  struct dirent *open;
  int           k;
  cpt = 0;
  while ((open = readdir(dir)) != NULL)
    if (my_strcmpamoi2(open->d_name, ".") != 1 &&
	my_strcmpamoi2(open->d_name, "..") != 1 &&
	checkextension(open->d_name) == 1)
      {
	if (stat(my_strcatwoman("tetriminos/", open->d_name), &sb) == -1)
	  exit(84);
	infos->name[cpt] = parsename(open->d_name);
	infos->recupval = recupint(stringmap(open->d_name));
	if (iserror(infos->recupval[0]) == 1 ||
	    checkn(open->d_name) == 1)
	    infos = list_error(infos, cpt);
	else
	  {
	    infos = modif_list(infos, cpt, sb, open->d_name);
	    count++;
	  }
	cpt++;
      }
  infos = make_listless(infos, count, cpt);
  return (infos);
}

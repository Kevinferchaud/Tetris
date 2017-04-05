/*
** print_tetrideb.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:36:22 2017 ferchaud kevin
** Last update Sun Mar 19 16:24:11 2017 ferchaud kevin
*/

#include "my.h"

void            print_sure(t_list *inf)
{
  int           cpt;
  int           cpt2;

  cpt2 = -1;
  cpt = count_tetri();
  my_printf("Tetriminos : %d\n", count_tetri());
  while (++cpt2 < cpt)
    {
      if (iserror(inf->size[cpt2]) == 1 ||
	  ts(gnb1(inf->size[cpt2]), gnb2(inf->size[cpt2]),
	     inf->tetri[cpt2]) == 1)
	my_printf("Tetriminos : Name %s : Error\n", inf->name[cpt2]);
      else
	my_printf("Tetriminos : Name %s : Size %s :  Color %s :\n%s",
		  inf->name[cpt2], inf->size[cpt2],
		  inf->color[cpt2], inf->tetri[cpt2]);
    }
}

t_list          *print_tetri(t_list *inf)
{
  int           test;
  int           cpt;

  test = 0;
  while (test == 0)
    {
      test = 1;
      cpt = -1;
      while (inf->name[++cpt + 1] != NULL)
	if (my_strcmptri(inf->name[cpt], inf->name[cpt + 1]) > 0)
	  {
	    test = 0;
	    inf = swap_infos(inf, cpt);
	  }
    }
  inf->nbtetri = cpt;
  return (inf);
}

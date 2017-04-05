/*
** test_init_tet.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:45:59 2017 ferchaud kevin
** Last update Sun Mar 19 17:32:27 2017 ferchaud kevin
*/

#include "my.h"

int     ts(int larg, int longe, char *str)
{
  int   cpts;
  int   stk;
  int   cptl;
  int   cpt;

  cptl = 0;
  stk = 0;
  cpt = -1;
  while (str[cpt + 1] != '\0')
    {
      cpts = 0;
      while (str[++cpt] != '\n')
	cpts++;
      while (str[--cpt] != '*')
	cpts--;
      while (str[++cpt] != '\n');
      if (stk < cpts)
	stk = cpts;
      cptl++;
    }
  if (cptl != longe)
    return (1);
  if (stk != larg)
    return (1);
  return (0);
}

m_list          **init_mlist(t_list *infos)
{
  m_list        **list;
  int           cpt;
  int           cpt2;

  cpt = -1;
  cpt2 = 0;
  if ((list = malloc(sizeof(m_list *) * (infos->nbtetri + 1))) == NULL)
    exit(84);
  while (infos->name[++cpt] != NULL)
    {
      if (my_strcmpamoi2("error", infos->tetri[cpt]) != 1 &&
	  ts(gnb1(infos->size[cpt]), gnb2(infos->size[cpt]), infos->tetri[cpt]) != 1)
	{
	  if ((list[cpt2] = malloc(sizeof(m_list))) == NULL)
	    exit(84);
	  list[cpt2]->tetri = recuptetri(infos->tetri[cpt], infos, cpt);
	  list[cpt2]->x = gnb1(infos->size[cpt]);
	  list[cpt2]->y = gnb2(infos->size[cpt]);
	  list[cpt2++]->color = my_getnbr(infos->color[cpt]);
	}
    }
  list[cpt2] = NULL;
  return (list);
}

cpt_list        *init_cpts()
{
  cpt_list	*st;
  if ((st = malloc(sizeof(cpt_list))) == NULL)
    exit(84);
  st->cpt = 0;
  st->cpt3 = -1;
  if ((st->ints = malloc(sizeof(char *) * 4)) == NULL)
    exit(84);
  return (st);
}


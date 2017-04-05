/*
** print_tab.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:32:04 2017 ferchaud kevin
** Last update Sat Mar 18 16:33:40 2017 ferchaud kevin
*/

#include "my.h"

void            print_tab_bat(int cpt2, int cpt)
{
  attron(COLOR_PAIR(2));
  mvprintw(cpt2 + 1, 40 + cpt, "|");
  attroff(COLOR_PAIR(2));
}

void            print_tabagain(int larg, int haut)
{
  int           cpt;

  cpt = -1;
  attron(COLOR_PAIR(2));
  while (++cpt <= larg + 1)
    mvprintw(haut + 1, 40 + cpt, "-");
  attroff(COLOR_PAIR(2));
}

void            print_tab(char **tab1, int haut, int larg)
{
  int           cpt;
  int           cpt2;

  cpt = -1;
  attron(COLOR_PAIR(2));
  while (++cpt <= larg + 1)
    mvprintw(0, 40 + cpt, "-");
  attroff(COLOR_PAIR(2));
  cpt2 = -1;
  while (++cpt2 < haut)
    {
      cpt = -2;
      while (++cpt <= larg)
	{
	  if (cpt == -1 || cpt == larg)
	    print_tab_bat(cpt2, cpt + 1);
	  else
	    if (tab1[cpt2][cpt] == ' ')
	      mvprintw(cpt2 + 1, 41 + cpt, " ");
	    else
	      print_color(tab1[cpt2][cpt] - '0', cpt, cpt2, 41);
	}
    }
  print_tabagain(larg, haut);
}

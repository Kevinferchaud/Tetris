/*
** print_color2.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:31:31 2017 ferchaud kevin
** Last update Sat Mar 18 16:31:56 2017 ferchaud kevin
*/

#include "my.h"

void            print_colorsix(int cpt2, int cpt, int len)
{
  attron(COLOR_PAIR(6));
  mvprintw(cpt2 + 1, len + cpt, "*");
  attroff(COLOR_PAIR(6));
}

void            print_colorseven(int cpt2, int cpt, int len)
{
  attron(COLOR_PAIR(7));
  mvprintw(cpt2 + 1, len + cpt, "*");
  attroff(COLOR_PAIR(7));
}

void            print_color(int val, int cpt, int cpt2, int len)
{
  if (val == 1)
    print_colorone(cpt2, cpt, len);
  if (val == 2)
    print_colortwo(cpt2, cpt, len);
  if (val == 3)
    print_colorthree(cpt2, cpt, len);
  if (val == 4)
    print_colorfour(cpt2, cpt, len);
  if (val == 5)
    print_colorfive(cpt2, cpt, len);
  if (val == 6)
    print_colorsix(cpt2, cpt, len);
  if (val == 7)
    print_colorseven(cpt2, cpt, len);
}

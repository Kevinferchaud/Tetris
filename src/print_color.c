/*
** print_color.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:30:47 2017 ferchaud kevin
** Last update Sat Mar 18 16:31:27 2017 ferchaud kevin
*/

#include "my.h"

void            print_colorone(int cpt2, int cpt, int len)
{
  attron(COLOR_PAIR(1));
  mvprintw(cpt2 + 1, len + cpt, "*");
  attroff(COLOR_PAIR(1));
}

void            print_colortwo(int cpt2, int cpt, int len)
{
  attron(COLOR_PAIR(2));
  mvprintw(cpt2 + 1, len + cpt, "*");
  attroff(COLOR_PAIR(2));
}

void            print_colorthree(int cpt2, int cpt, int len)
{
  attron(COLOR_PAIR(3));
  mvprintw(cpt2 + 1, len + cpt, "*");
  attroff(COLOR_PAIR(3));
}

void            print_colorfour(int cpt2, int cpt, int len)
{
  attron(COLOR_PAIR(4));
  mvprintw(cpt2 + 1, len + cpt, "*");
  attroff(COLOR_PAIR(4));
}

void            print_colorfive(int cpt2, int cpt, int len)
{
  attron(COLOR_PAIR(5));
  mvprintw(cpt2 + 1, len + cpt, "*");
  attroff(COLOR_PAIR(5));
}

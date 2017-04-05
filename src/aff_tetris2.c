/*
** aff_tetris2.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:27:03 2017 ferchaud kevin
** Last update Sat Mar 18 16:28:15 2017 ferchaud kevin
*/

#include "my.h"

void    print_L5less()
{
  attron(COLOR_PAIR(5));
  printw("**");
  attroff(COLOR_PAIR(5));
  attron(COLOR_PAIR(6));
  printw("*****");
  attroff(COLOR_PAIR(6));
}

void    print_L5()
{
  printw("  ");
  attron(COLOR_PAIR(1));
  printw("**");
  attroff(COLOR_PAIR(1));
  printw("  ");
  attron(COLOR_PAIR(2));
  printw("******");
  attroff(COLOR_PAIR(2));
  printw("  ");
  attron(COLOR_PAIR(3));
  printw("**");
  attroff(COLOR_PAIR(3));
  printw("  ");
  attron(COLOR_PAIR(4));
  printw("*");
  attroff(COLOR_PAIR(4));
  printw("    ");
  attron(COLOR_PAIR(4));
  printw("*");
  attroff(COLOR_PAIR(4));
  print_L5less();
}

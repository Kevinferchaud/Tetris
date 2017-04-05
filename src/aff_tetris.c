/*
** aff_tetris.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Mon Feb 27 15:08:44 2017 ferchaud kevin
** Last update Sat Mar 18 16:27:23 2017 ferchaud kevin
*/

#include "my.h"

void            print_L1()
{
  attron(COLOR_PAIR(1));
  printw("******");
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(2));
  printw("******");
  attroff(COLOR_PAIR(2));
  attron(COLOR_PAIR(3));
  printw("******");
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(4));
  printw("******");
  attroff(COLOR_PAIR(4));
  attron(COLOR_PAIR(5));
  printw("**");
  attroff(COLOR_PAIR(5));
  attron(COLOR_PAIR(6));
  printw("*****");
  attroff(COLOR_PAIR(6));
}

void    print_L2()
{
  printw("  ");
  attron(COLOR_PAIR(1));
  printw("**");
  attroff(COLOR_PAIR(1));
  printw("  ");
  attron(COLOR_PAIR(2));
  printw("*");
  attroff(COLOR_PAIR(2));
  printw("       ");
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
  printw("  ");
  attron(COLOR_PAIR(6));
  printw("*");
  attroff(COLOR_PAIR(6));
}

void    print_L3()
{
  printw("  ");
  attron(COLOR_PAIR(1));
  printw("**");
  attroff(COLOR_PAIR(1));
  printw("  ");
  attron(COLOR_PAIR(2));
  printw("***");
  attroff(COLOR_PAIR(2));
  printw("     ");
  attron(COLOR_PAIR(3));
  printw("**");
  attroff(COLOR_PAIR(3));
  printw("  ");
  attron(COLOR_PAIR(4));
  printw("*****");
  attroff(COLOR_PAIR(4));
  printw(" ");
  attron(COLOR_PAIR(5));
  printw("**");
  attroff(COLOR_PAIR(5));
  attron(COLOR_PAIR(6));
  printw("*****");
  attroff(COLOR_PAIR(6));
}

void	print_L4less()
{
  printw("    ");
  attron(COLOR_PAIR(4));
  printw("*");
  attroff(COLOR_PAIR(4));
  attron(COLOR_PAIR(5));
  printw("**");
  attroff(COLOR_PAIR(5));
  printw("    ");
  attron(COLOR_PAIR(6));
  printw("*");
  attroff(COLOR_PAIR(6));
}

void    print_L4()
{
  printw("  ");
  attron(COLOR_PAIR(1));
  printw("**");
  attroff(COLOR_PAIR(1));
  printw("  ");
  attron(COLOR_PAIR(2));
  printw("*");
  attroff(COLOR_PAIR(2));
  printw("       ");
  attron(COLOR_PAIR(3));
  printw("**");
  attroff(COLOR_PAIR(3));
  printw("  ");
  attron(COLOR_PAIR(4));
  printw("*");
  attroff(COLOR_PAIR(4));
  print_L4less();
}

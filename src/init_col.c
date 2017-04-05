/*
** tetris.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris/tmp
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Wed Mar 15 17:28:06 2017 ferchaud kevin
** Last update Sat Mar 18 16:51:24 2017 ferchaud kevin
*/

#include "my.h"

void		init_colors()
{
  start_color();
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_WHITE, COLOR_WHITE);
  init_pair(3, COLOR_CYAN, COLOR_CYAN);
  init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(5, COLOR_GREEN, COLOR_GREEN);
  init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(7, COLOR_BLUE, COLOR_BLUE);
  init_pair(8, COLOR_BLACK, COLOR_BLACK);
  init_pair(9, COLOR_BLACK, COLOR_RED);
  init_pair(10, COLOR_WHITE, COLOR_BLUE);
  init_pair(11, COLOR_RED, COLOR_WHITE);
}

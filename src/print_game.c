/*
** print_game.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:50:14 2017 ferchaud kevin
** Last update Sat Mar 18 16:51:17 2017 ferchaud kevin
*/

#include "my.h"

void            print_barre()
{
  attron(COLOR_PAIR(3));
  printw("------------------------------- \n");
  attroff(COLOR_PAIR(3));
}

void            print_bat()
{
  attron(COLOR_PAIR(2));
  printw("|");
  attroff(COLOR_PAIR(2));
}

void            print_score2()
{
  printw("\n");
  print_bat();
  printw(" Level                    ");
  print_bat();
  printw("\n");
  print_bat();
  printw("                          ");
  print_bat();
  printw("\n");
  print_bat();
  printw(" Timer                    ");
  print_bat();
  printw("\n");
  print_bat();
  printw("                          ");
  print_bat();
  printw("\n");
  attron(COLOR_PAIR(2));
  printw("\\--------------------------/\n");
  attroff(COLOR_PAIR(2));
}

void            print_score()
{
  attron(COLOR_PAIR(2));
  printw("\n/--------------------------\\\n");
  printw("|");
  attroff(COLOR_PAIR(2));
  printw("                          ");
  print_bat();
  attroff(COLOR_PAIR(2));
  printw("\n");
  print_bat();
  printw(" High Score               ");
  print_bat();
  printw("\n");
  print_bat();
  printw(" Score                    ");
  print_bat();
  printw("\n");
  print_bat();
  printw("                          ");
  print_bat();
  printw("\n");
  print_bat();
  printw(" Lines                    ");
  print_bat();
  print_score2();
}

void            print_tetris()
{
  print_barre();
  printw("\n");
  print_L1();
  printw("\n");
  print_L2();
  printw("\n");
  print_L3();
  printw("\n");
  print_L4();
  printw("\n");
  print_L5();
  printw("\n\n");
  print_barre();
  print_score();
}

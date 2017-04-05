/*
** print2.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 17:05:44 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 17:33:57 2017 Maxime Le Huu Nho
*/

#include "my.h"

void			print_finalscore(int score, int test)
{
  if (test == 0)
    {
      attron(COLOR_PAIR(9));
      mvprintw(5, 40, "Score : %d", score);
      attroff(COLOR_PAIR(9));
    }
  else
    {
      attron(COLOR_PAIR(10));
      mvprintw(9, 40, "Score : %d", score);
      attroff(COLOR_PAIR(10));
    }
}

void			print_bscore(t_plat *game)
{
  int			high;
  int			test;

  high = readmyscore();
  test = 0;
  if (game->highscore > high)
    {
      print_newrecord();
      test = 1;
      writemyscore(game->highscore);
    }
  print_finalscore(game->score, test);
}

void			print_gameover(t_plat *game)
{
  char			**str;

  if ((str = malloc(sizeof(char *) * 16)) == NULL)
    exit(84);
  str[0] = "*****   **    ** **  ****";
  str[1] = "*      *  *  *  *  * *   ";
  str[2] = "*  **  ****  *  *  * *** ";
  str[3] = "*   *  *  *  *  *  * *   ";
  str[4] = "*****  *  *  *  *  * ****";
  str[5] = "  ***** *   * **** ***** ";
  str[6] = "  *   * *   * *    *   * ";
  str[7] = "  *   * *   * ***  ****  ";
  str[8] = "  *   *  * *  *    *   * ";
  str[9] = "  *****   *   **** *   * ";
  str[10] = NULL;
  clear();
  print_gameoverless(str, 0);
  print_bscore(game);
  refresh();
}

void			print_next(t_plat *game)
{
  int			cpt;
  int			cpt2;

  attron(COLOR_PAIR(11));
  mvprintw(0, 44 + game->mapsize[1], " next ");
  attroff(COLOR_PAIR(11));
  cpt = -1;
  while (game->tetri[game->c2]->tetri[++cpt])
    {
      cpt2 = -1;
      while (game->tetri[game->c2]->tetri[cpt][++cpt2] != '\0')
	if (game->tetri[game->c2]->tetri[cpt][cpt2] == '*')
	    print_color(game->tetri[game->c2]->color,
			cpt2 + 44 + game->mapsize[1], cpt + 1, 2);
    }
}

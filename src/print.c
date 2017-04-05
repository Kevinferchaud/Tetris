/*
** print.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 17:01:19 2017 Maxime Le Huu Nho
** Last update Sun Mar 19 17:23:03 2017 ferchaud kevin
*/

#include "my.h"

void			print_tetrimino(t_plat *game, m_list *tetri)
{
  int			len;
  int			cpt;
  int			cpt2;

  cpt = -1;
  len = (game->x) - (tetri->x / 2);
  while (tetri->tetri[++cpt])
    {
      cpt2 = -1;
      while (++cpt2 < my_strlen(tetri->tetri[cpt]))
	if (tetri->tetri[cpt][cpt2] != ' ')
	  print_color(tetri->color, cpt2, game->y + cpt - 1, len);
    }
}

void			print_lettergameover(int cpt, int cpt2, int col)
{
  if (col == 0)
    {
      attron(COLOR_PAIR(8));
      mvprintw(cpt, cpt2, "*");
      attroff(COLOR_PAIR(8));
    }
  else
    {
      attron(COLOR_PAIR(2));
      mvprintw(cpt, cpt2, "*");
      attroff(COLOR_PAIR(2));
    }
}

void			print_space(int cpt, int cpt2, int col)
{
  if (col == 0)
    {
      attron(COLOR_PAIR(1));
      mvprintw(cpt, cpt2, " ");
      attroff(COLOR_PAIR(1));
    }
  else
    {
      attron(COLOR_PAIR(7));
      mvprintw(cpt, cpt2, " ");
      attroff(COLOR_PAIR(7));
    }
}

void			print_gameoverless(char **str, int decal)
{
  int			cpt;
  int			cpt2;

  cpt = -1;
  while (str[++cpt])
    {
      cpt2 = -1;
      while (str[cpt][++cpt2] != '\0')
	if (str[cpt][cpt2] == '*')
	  print_lettergameover(cpt, cpt2 + decal, decal);
	else
	  print_space(cpt, cpt2 + decal, decal);
    }
}

void			print_newrecord()
{
  char			**str;

  if ((str = malloc(sizeof(char *) * 6)) == NULL)
    exit(84);
  str[0] = " *    * **** *     *   ***** **** **** ***** ***** ***  ";
  str[1] = " **   * *    *     *   *   * *    *    *   * *   * *  * ";
  str[2] = " * *  * ***  *  *  *   ****  **** *    *   * ****  *  * ";
  str[3] = " *   ** *     * * *    *   * *    *    *   * *   * *  * ";
  str[4] = " *    * ****   * *     *   * **** **** ***** *   * ***  ";
  str[5] = NULL;
  print_gameoverless(str, 40);
}

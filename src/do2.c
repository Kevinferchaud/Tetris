/*
** do2.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 15:48:30 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 15:54:15 2017 Maxime Le Huu Nho
*/

#include "my.h"

char			*check_pos(char *buffer, char *tmp,
				   char **key, t_plat **game)
{
  int			val;

  tmp = strcatamoi(tmp, buffer);
  val = 0;
  if ((my_strncmpmoi(tmp, key[5], my_strlen(tmp) - 1)) == 0 ||
      (my_strncmpmoi(tmp, key[4], my_strlen(tmp) - 1)) == 0)
    val = 1;
  if (val == 0)
    {
      tmp[0] = '\0';
      return (tmp);
    }
  if (my_strcmpamoi2(tmp, key[4]) == 1)
    do_kq(game, (*game)->tetri[(*game)->c], key);
  return (tmp);
}

void			interface_stop(char **key)
{
  char			**str;

  if ((str = malloc(sizeof(char *) * 6)) == NULL)
    exit(84);
  str[0] = " *****   **   *   *  *****  **** ";
  str[1] = " *   *  *  *  *   *  *      *    ";
  str[2] = " *****  ****  *   *  *****  ***  ";
  str[3] = " *      *  *  *   *      *  *    ";
  str[4] = " *      *  *  *****  *****  **** ";
  str[5] = NULL;
  print_gameoverless(str, 20);
  attron(COLOR_PAIR(10));
  mvprintw(9, 33, "Continue");
  mvprintw(12, 35, "Quit");
  mvprintw(18, 0, " By FERCHAUD Kevin & LE HUU NHO Maxime ");
  attroff(COLOR_PAIR(10));
}

void			do_kp(t_plat **game, m_list *tetri, char **key)
{
  char			*tmp;
  char			*buffer;
  int			i;

  if ((tmp = malloc(sizeof(char))) == NULL)
    exit(84);
  if ((buffer = malloc(sizeof(char) * 101)) == NULL)
    exit(84);
  tmp[0] = '\0';
  clear();
  interface_stop(key);
  refresh();
  while (my_strcmpamoi2(tmp, key[5]) != 1)
    {
      i = read(0, buffer, 100);
      if (i > 0)
	tmp = check_pos(buffer, tmp, key, game);
    }
  refresh();
}

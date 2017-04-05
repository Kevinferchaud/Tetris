/*
** check2.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 17:36:27 2017 Maxime Le Huu Nho
** Last update Sun Mar 19 17:38:51 2017 ferchaud kevin
*/

#include "my.h"

int			scheck_left(m_list *tetri, t_plat **game)
{
  int			cpt;
  int			cpt2;
  int		       x;
  int		       y;

  cpt = -1;
  y = (*game)->y;
  while (tetri->tetri[++cpt])
    {
      cpt2 = -1;
      x = (*game)->x - tetri->x / 2;
      while (++cpt2 < my_strlen(tetri->tetri[cpt]))
	{
	  if (tetri->tetri[cpt][cpt2] == '*')
	    if ((*game)->game[y - 1][x - 42] >= '1' &&
		(*game)->game[y - 1][x - 42] <= '7')
	      return (0);
	    else
	      if (x < 42)
		return (0);
	  x++;
	}
      y++;
    }
  return (1);
}

int			scheck_right(m_list *tetri, t_plat **game)
{
  int			cpt;
  int			cpt2;
  int		       x;
  int		       y;

  cpt = -1;
  y = (*game)->y;
  while (tetri->tetri[++cpt])
    {
      cpt2 = -1;
      x = (*game)->x - tetri->x / 2;
      while (++cpt2 < my_strlen(tetri->tetri[cpt]))
	{
	  if (tetri->tetri[cpt][cpt2] == '*')
	    if ((*game)->game[y - 1][x - 40] >= '1' &&
		(*game)->game[y - 1][x - 40] <= '7')
	      return (0);
	    else
	      if (x - 40 > (*game)->mapsize[1] - 1)
		return (0);
	  x++;
	}
      y++;
    }
  return (1);
}

void			checkline_tetri(t_plat **game, t_data **data, int cpt)
{
  int			cpt2;
  int			len;
  static int		save;

  while ((*game)->game[++cpt])
    {
      len = 0;
      cpt2 = -1;
      while ((*game)->game[cpt][++cpt2] != '\0')
	if ((*game)->game[cpt][cpt2] >= '1' &&
	    (*game)->game[cpt][cpt2] <= '7')
	  len++;
      if (len == my_strlen((*game)->game[cpt]))
	{
	  (*game)->line++;
	  suppr_line(game, cpt);
	  (*game)->score += 100;
	  save += 100;
	}
    }
  if (save > 1000)
    {
      (*data)->l++;
      save = 0;
    }
}

void			checkend(t_plat *game)
{
  int			test;
  char			buf[10];

  test = 1;
  if (game->game[0][game->x - 41] >= '1' &&
      game->game[0][game->x - 41] <= '7')
    test = 0;
  if (test == 0)
    {
      gest_read(0);
      gest_read(1);
      print_gameover(game);
      read(0, buf, 9);
      endwin();
      gest_read(0);
      exit(0);
    }
}

void			checkhscore(t_plat **game)
{
  if ((*game)->score > (*game)->highscore)
    (*game)->highscore = (*game)->score;
}

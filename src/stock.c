/*
** stock.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 17:43:27 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 20:47:44 2017 ferchaud kevin
*/

#include "my.h"

void			stock_mytetri(t_plat **game, m_list *tetri)
{
  int			x;
  int			y;
  int			x1;
  int			y1;

  y1 = (*game)->y;
  y = 0;
  while (tetri->tetri[y])
    {
      x = 0;
      x1 = (*game)->x - tetri->x / 2;
      while (tetri->tetri[y][x])
	{
	  if (tetri->tetri[y][x] == '*')
	    (*game)->game[y1 - 1][x1 - 41] = tetri->color + '0';
	  x++;
	  x1++;
	}
      y++;
      y1++;
    }
}

int			stock_tetribufferless(t_plat **game, m_list *tetri)
{
  stock_mytetri(game, tetri);
  (*game)->x = 41 + ((*game)->mapsize[1] / 2);
  (*game)->y = 1;
  (*game)->score += 10;
  return (0);
}

int			stock_tetribuffer(m_list *tetri, t_plat **game)
{
  int			cpt;
  int			cpt2;
  int		       x;
  int		       y;

  cpt = -1;
  y = (*game)->y;
  while (tetri->tetri[++cpt])
    {
      if (y == (*game)->mapsize[0])
	return (stock_tetribufferless(game, tetri));
      cpt2 = -1;
      x = (*game)->x - tetri->x / 2;
      while (++cpt2 < my_strlen(tetri->tetri[cpt]))
	{
	  if (tetri->tetri[cpt][cpt2] == '*')
	    if ((*game)->game[y][x - 41] >= '1' &&
		(*game)->game[y][x - 41] <= '7')
	      return (stock_tetribufferless(game, tetri));
	  x++;
	}
      y++;
    }
  return (1);
}

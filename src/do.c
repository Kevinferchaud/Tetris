/*
** do.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 15:44:28 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 19:14:54 2017 ferchaud kevin
*/

#include "my.h"

void			do_kl(t_plat **game, m_list *tetri, char **key)
{
  if (scheck_left((*game)->tetri[(*game)->c], game) != 0)
    (*game)->x--;
}

void			do_kr(t_plat **game, m_list *tetri, char **key)
{
  if (scheck_right((*game)->tetri[(*game)->c], game) != 0)
    (*game)->x++;
}

void			do_kt(t_plat **game, m_list *tetri, char **key)
{
}

void			do_kd(t_plat **game, m_list *tetri, char **key)
{
  if (stock_tetribuffer((*game)->tetri[(*game)->c], game) == 0)
    {
      (*game)->c = (*game)->c2;
      (*game)->c2 = rand() % (*game)->nbtetri;
    }
  else
    (*game)->y++;
}

void			do_kq(t_plat **game, m_list *tetri, char **key)
{
  endwin();
  gest_read(0);
  exit(0);
}

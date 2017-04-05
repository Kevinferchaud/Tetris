/*
** print3.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 20:37:40 2017 ferchaud kevin
** Last update Sat Mar 18 20:44:37 2017 ferchaud kevin
*/

#include "my.h"

void                    print_map(t_plat *game, t_data *data)
{
  print_tetris();
  print_tab(game->game, data->mapsize[0], data->mapsize[1]);
  print_tetrimino(game, game->tetri[game->c]);
  if (data->w == 0)
    print_next(game);
}

void                    print_play(t_plat **game, t_data **data,
				   double timepast)
{
  checkline_tetri(game, data, -1);
  mvprintw(12, 24 - lenint((*game)->highscore), "%d", (*game)->highscore);
  mvprintw(13, 24 - lenint((*game)->score), "%d", (*game)->score);
  mvprintw(15, 24 - lenint((*game)->line), "%d", (*game)->line);
  mvprintw(16, 24 - lenint((*data)->l), "%d", (*data)->l);
  mvprintw(18, 22 - lenint((int)(timepast / 18000)), "%d(s)",
	   (int)(timepast / 18000));
  checkhscore(game);
  checkend(*game);
  refresh();
}

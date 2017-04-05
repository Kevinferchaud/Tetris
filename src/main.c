/*
** main.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
**
** Made by Maxime Le Huu Nho
** Login   <lehuun_m@epitech.net>
**
** Started on  Tue Feb 21 14:56:43 2017 Maxime Le Huu Nho
** Last update Mon Apr  3 16:17:39 2017 ferchaud kevin
*/

#include "my.h"

t_list                  *check_lentetri(t_list *infos, t_plat **data, char **av)
{
  int                   cpt;

  cpt = -1;
  (*data)->nbtetri = 0;
  while (++cpt < infos->nbtetri)
    {
      if (iserror(infos->size[cpt]) == 1 &&
	  gnb1(infos->size[cpt]) > (*data)->mapsize[1])
	infos = list_error(infos, cpt);
      else
	if (iserror(infos->size[cpt]) == 1 &&
	    gnb2(infos->size[cpt]) > (*data)->mapsize[0])
	  infos = list_error(infos, cpt);
	else
	  (*data)->nbtetri++;
    }
  if ((*data)->nbtetri == 0)
    my_usage(av, 1);
  return (infos);
}

void			tetris(char **av)
{
  char			**cmds;
  char			**cmdl;
  t_data		*data;
  t_list		*infos;
  char			**touch;
  t_plat		*plat;

  cmdl = create_cmd();
  cmds = create_cmd2();
  check_args(av, cmds, cmdl);
  data = fill_struct(av);
  data = check_margument(cmds, data, cmdl, av);
  touch = stock_touch(data);
  check_touch(touch, av);
  infos = stock_tetri();
  infos->nbtetri = count_tetri();
  plat = init_plat(data, infos);
  infos = check_lentetri(infos, &plat, av);
  gest_read(1);
  if (data->d == 1)
    aff_debug(data, infos, touch, plat);
  else
    play_tetris(data, touch, plat);
}

char			*init_tetrirand(t_plat **game)
{
  char			*tmp;

  if ((tmp = malloc(1 * sizeof(char))) == NULL)
    exit(84);
  tmp[0] = '\0';
  (*game)->c = rand() % (*game)->nbtetri;
  (*game)->c2 = rand() % (*game)->nbtetri;
  return (tmp);
}

void			play_tetris(t_data *data, char **touch, t_plat *game)
{
  char			*buffer;

  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
  gest_read(2);
  if ((buffer = malloc(101 * sizeof(char))) == NULL)
    exit(84);
  init_colors();
  play_tetrisless(game, buffer, touch, data);
}

int			main(int ac, char **av, char **env)
{
  char			*term;
  char			c = 208;

  my_printf("%b\n", 208);
  if ((term = get_elem(env, 0)) == NULL)
    exit(84);
  if (setupterm(term, 0, NULL) == -1)
    exit(84);
  srand(getpid());
  tetris(av);
  gest_read(0);
  return (0);
}

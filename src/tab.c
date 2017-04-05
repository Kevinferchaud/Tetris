/*
** tab.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 16:05:18 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 21:01:24 2017 ferchaud kevin
*/

#include "my.h"

char			**create_cmd2()
{
  char			**cmd;

  if ((cmd = malloc(20 * sizeof(char *))) == NULL)
    exit(84);
  cmd[0] = my_strdup("-l");
  cmd[1] = my_strdup("-kl");
  cmd[2] = my_strdup("-kr");
  cmd[3] = my_strdup("-kt");
  cmd[4] = my_strdup("-kd");
  cmd[5] = my_strdup("-kq");
  cmd[6] = my_strdup("-kp");
  cmd[7] = my_strdup("-w");
  cmd[8] = my_strdup("-d");
  cmd[9] = NULL;
  return (cmd);
}

char			**create_cmd()
{
  char			**cmd;

  if ((cmd = malloc(20 * sizeof(char *))) == NULL)
    exit(84);
  cmd[0] = my_strdup("--level=");
  cmd[1] = my_strdup("--key-left=");
  cmd[2] = my_strdup("--key-right=");
  cmd[3] = my_strdup("--key-turn=");
  cmd[4] = my_strdup("--key-drop=");
  cmd[5] = my_strdup("--key-quit=");
  cmd[6] = my_strdup("--key-pause=");
  cmd[7] = my_strdup("--without-next=");
  cmd[8] = my_strdup("--debug");
  cmd[9] = my_strdup("--map-size=");
  cmd[10] = NULL;
  return (cmd);
}

t_data			*fill_struct(char **av)
{
  t_data		*data;

  if ((data = malloc(sizeof(t_data))) == NULL)
    exit(84);
  data->av = av;
  data->l = 1;
  data->kl = my_strdup(tigetstr("kcub1"));
  data->kr = my_strdup(tigetstr("kcuf1"));
  data->kt = my_strdup(tigetstr("kcuu1"));
  data->kd = my_strdup(tigetstr("kcud1"));
  data->kq = my_strdup("q");
  data->kp = my_strdup(" ");
  data->mapsize[0] = 20;
  data->mapsize[1] = 10;
  data->w = 0;
  data->d = 0;
  return (data);
}

t_args			*init_args()
{
  t_args		*args;

  if ((args = malloc(10 * sizeof(t_args))) == NULL)
    exit(84);
  args[0] = &init_l;
  args[1] = &init_kl;
  args[2] = &init_kr;
  args[3] = &init_kt;
  args[4] = &init_kd;
  args[5] = &init_kq;
  args[6] = &init_kp;
  args[7] = &init_w;
  args[8] = &init_d;
  args[9] = &init_ms;
  return (args);
}

t_touch			*init_touch()
{
  t_touch		*touch;

  if ((touch = malloc(7 * sizeof(t_touch))) == NULL)
    exit(84);
  touch[0] = &do_kl;
  touch[1] = &do_kr;
  touch[2] = &do_kt;
  touch[3] = &do_kd;
  touch[4] = &do_kq;
  touch[5] = &do_kp;
  touch[6] = NULL;
  return (touch);
}

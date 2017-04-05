/*
** init2.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 16:26:14 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 21:15:17 2017 ferchaud kevin
*/

#include "my.h"

t_data			*init_kq(char *str, t_data *data)
{
  if (str == NULL || str[0] == '\0')
    my_usage(data->av, 1);
  data->kq = str;
  return (data);
}

t_data			*init_kp(char *str, t_data *data)
{
  if (str == NULL || str[0] == '\0')
    my_usage(data->av, 1);
  data->kp = str;
  return (data);
}

t_data			*init_w(char *str, t_data *data)
{
  data->w = 1;
  return (data);
}

t_data			*init_d(char *str, t_data *data)
{
  data->d = 1;
  return (data);
}

t_data			*init_ms(char *str, t_data *data)
{
  int			i;

  if (str == NULL || str[0] == '\0')
    my_usage(data->av, 1);
  i = 0;
  while (str[i])
    {
      if ((str[i] < '1' || str[i] > '9') && str[i] != ',')
	my_usage(data->av, 1);
      i++;
    }
  i = my_strtol(str, &str);
  data->mapsize[0] = i;
  i = my_strtol(str, &str);
  data->mapsize[1] = i;
  return (data);
}

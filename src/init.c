/*
** init.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 16:22:40 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 21:02:56 2017 ferchaud kevin
*/

#include "my.h"

t_data			*init_l(char *str, t_data *data)
{
  int			res;

  if (str == NULL || str[0] == '\0')
    my_usage(data->av, 1);
  res = my_getnbr(str);
  if (res < 1 || res > 10)
    my_usage(data->av, 1);
  data->l = res;
  return (data);
}

t_data			*init_kl(char *str, t_data *data)
{
  if (str == NULL || str[0] == '\0')
    my_usage(data->av, 1);
  data->kl = str;
  return (data);
}

t_data			*init_kr(char *str, t_data *data)
{
  if (str == NULL || str[0] == '\0')
    my_usage(data->av, 1);
  data->kr = str;
  return (data);
}

t_data			*init_kt(char *str, t_data *data)
{
  if (str == NULL || str[0] == '\0')
    my_usage(data->av, 1);
  data->kt = str;
  return (data);
}

t_data			*init_kd(char *str, t_data *data)
{
  if (str == NULL || str[0] == '\0')
    my_usage(data->av, 1);
  data->kd = str;
  return (data);
}

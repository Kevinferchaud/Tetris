/*
** tab2.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 16:08:33 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 16:19:07 2017 Maxime Le Huu Nho
*/

#include "my.h"

char			**stock_touch(t_data *data)
{
  char			**res;

  if ((res = malloc(7 * sizeof(char *))) == NULL)
    exit(84);
  res[0] = my_strdup(data->kl);
  res[1] = my_strdup(data->kr);
  res[2] = my_strdup(data->kt);
  res[3] = my_strdup(data->kd);
  res[4] = my_strdup(data->kq);
  res[5] = my_strdup(data->kp);
  res[6] = NULL;
  return (res);
}

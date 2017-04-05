/*
** tools.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 15:54:48 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 15:56:49 2017 Maxime Le Huu Nho
*/

#include "my.h"

int			my_strtol(char *str, char **endptr)
{
  int			res;
  int			i;

  i = 0;
  res = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  i++;
	  *endptr = &str[i];
	  return (res);
	}
      res = res * 10 + (str[i] - '0');
      i++;
    }
  *endptr = NULL;
  return (res);
}

int			my_getnbr(char *str)
{
  int			res;
  int			i;
  int			test;

  i = 0;
  res = 0;
  test = 0;
  if (str[0] == '-')
    {
      i++;
      test = 1;
    }
  while (str[i])
    {
      res = res * 10 + (str[i] - '0');
      i++;
    }
  if (test == 1)
    res *= -1;
  return (res);
}

int	my_strcmptri(char *s1, char *s2)
{
  int	i;

  i = 0;
  while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}

int			my_strcmpamoi(char *s1, char *s2)
{
  int			i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}

int			my_strcmpamoi2(char *s1, char *s2)
{
  int			i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  if (s1[i] != s2[i])
    return (0);
  return (1);
}

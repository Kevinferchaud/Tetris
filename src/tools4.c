/*
** tools4.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 17:15:41 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 20:16:26 2017 ferchaud kevin
*/

#include "my.h"

void			gest_read(int i)
{
  static struct termios	old;
  static struct termios	new;

  if (i == 1)
    {
      ioctl(0, TCGETS, &old);
      new = old;
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      ioctl(0, TCSETS, &new);
    }
  else
    if (i == 2)
      {
	new.c_cc[VMIN] = 0;
	new.c_cc[VTIME] = 1;
	ioctl(0, TCSETS, &new);
      }
    else
      ioctl(0, TCSETS, &old);
}

int			my_strlena(char *str)
{
  int			cpt;

  cpt = -1;
  if (str == NULL)
    return (0);
  while (str[++cpt] != '\0');
  return (cpt);
}

char			*recup_av(char *str)
{
  char			*res;
  int			i;
  int			j;

  j = 0;
  i = 0;
  if ((res = malloc(my_strlen(str) * sizeof(char))) == NULL)
    exit (84);
  res[0] = '\0';
  while (str[i] != '=' && str[i] != '\0')
    i++;
  i++;
  while (str[i])
    res[j++] = str[i++];
  res[j] = '\0';
  return (res);
}

void			suppr_line(t_plat **game, int line)
{
  int			cpt;

  cpt = -1;
  if (line == 0)
    while ((*game)->game[line][++cpt] != '\0')
      (*game)->game[line][cpt] = ' ';
  while (--line >= 0)
    {
      cpt = -1;
      while ((*game)->game[line][++cpt] != '\0')
	(*game)->game[line + 1][cpt] = (*game)->game[line][cpt];
    }
}

char    *strcatamoi(char *s1, char *s2)
{
  char  *res;
  int   i;
  int   j;

  i = 0;
  j = 0;
  if ((res = malloc((my_strlena(s1) + my_strlena(s2) + 1)
		    * sizeof(char))) == NULL)
    return (NULL);
  while (s1 != NULL && s1[i] != '\0')
    {
      res[i] = s1[i];
      i++;
    }
  while (s2 != NULL && s2[j] != '\0')
    {
      res[i + j] = s2[j];
      j++;
    }
  res[i + j] = '\0';
  return (res);
}

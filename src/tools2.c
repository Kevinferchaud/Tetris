/*
** tools2.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 16:32:59 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 20:48:54 2017 ferchaud kevin
*/

#include "my.h"

void			aff_debug(t_data *data, t_list *infos, char **touch,
				  t_plat *game)
{
  char			buffer[10];

  my_putstr("*** DEBUG MODE ***\n");
  my_printf("Key Left : %k\n", data->kl);
  my_printf("Key Right : %k\n", data->kr);
  my_printf("Key Turn : %k\n", data->kt);
  my_printf("Key Drop : %k\n", data->kd);
  my_printf("Key Quit : %k\n", data->kq);
  my_printf("Key Pause : %k\n", data->kp);
  if (data->w == 1)
    my_printf("Next : No\n");
  else
    my_printf("Next : Yes\n");
  my_printf("Level : %d\n", data->l);
  my_printf("Size : %d*%d\n", data->mapsize[0], data->mapsize[1]);
  print_sure(infos);
  my_putstr("Press any key to start Tetris\n");
  read(0, buffer, 10);
  play_tetris(data, touch, game);
}

char			*int_to_char(int score)
{
  char			*res;
  int			cpt;
  int			len;

  if ((res = malloc(sizeof(char) * (lenint(score) + 1))) == NULL)
    exit(84);
  cpt = -1;
  len = lenint(score);
  while (++cpt < len)
    {
      res[cpt] = (score % 10) + '0';
      score /= 10;
    }
  res[cpt] = '\0';
  res = my_revstr(res);
  return (res);
}

int			lenint(int n)
{
  int			cpt;

  cpt = 0;
  if (n == 0)
    return (1);
  while (n > 0)
    {
      cpt++;
      n /= 10;
    }
  return (cpt);
}

int	my_strncmpmoi(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (n >= 0)
    while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i] && i < n)
      i++;
  else
    while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
      i++;
  return (s1[i] - s2[i]);
}

char			*get_elem(char **env, int i)
{
  int			j;
  int			k;
  char			*res;

  j = 0;
  k = 0;
  while (env[i])
    {
      if (my_strcmpamoi("TERM=", env[i]) == 1)
	{
	  if ((res = malloc(my_strlen(env[i]) * sizeof(char))) == NULL)
	    exit(84);
	  while (env[i][j] != '=')
	    j++;
	  j++;
	  while (env[i][j])
	    res[k++] = env[i][j++];
	  res[k] = '\0';
	  if (res[0] == '\0')
	    return (NULL);
	  return (res);
	}
      i++;
    }
  return (NULL);
}

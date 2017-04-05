/*
** annexe2.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:38:59 2017 ferchaud kevin
** Last update Sun Mar 19 17:28:20 2017 ferchaud kevin
*/

#include "my.h"

char            *my_strcatwoman(char *concat, char *suppr)
{
  char          *newstr;
  int           cpt;
  int           cpt2;
  int           u1;
  int           u2;

  cpt = -1;
  cpt2 = -1;
  if (concat == NULL)
    u1 = 0;
  else
    u1 = my_strlen(concat);
  if (suppr == NULL)
    u2 = 0;
  else
    u2 = my_strlen(suppr);
  newstr = malloc(sizeof(char) * (u1 + u2 + 1));
  if (concat != NULL)
    while (concat != NULL && concat[++cpt] != '\0')
      newstr[++cpt2] = concat[cpt];
  cpt = -1;
  while (suppr != NULL && suppr[++cpt] != '\0')
    newstr[++cpt2] = suppr[cpt];
  newstr[++cpt2] = '\0';
  return (newstr);
}

char                    *stringmap(char *pos)
{
  char                  buf[2];
  char                  *buff;
  int                   cpt;
  char                  *newname;
  int                   fd;
  int			i;

  cpt = 0;
  newname = my_strdup("tetriminos/");
  newname = my_strcatwoman(newname, pos);
  if ((fd = open(newname, O_RDONLY)) == -1)
    exit(84);
  while (read(fd, buf, 1) != 0)
    cpt++;
  if ((buff = malloc(sizeof(char) * (cpt + 1))) == NULL)
    exit(84);
  close(fd);
  if ((fd = open(newname, O_RDONLY)) == -1)
    exit(84);
  i = read(fd, buff, cpt);
  buff[i] = '\0';
  close(fd);
  return (buff);
}

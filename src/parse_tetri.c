/*
** parse_tetri.c for emacs in /home/kevin.ferchaud/PSU_2016_tetris
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sat Mar 18 16:41:20 2017 ferchaud kevin
** Last update Sat Mar 18 16:42:54 2017 ferchaud kevin
*/

#include "my.h"

char            *parsesize(char *larg, char *longe)
{
  char          *res;

  res = NULL;
  res = strcatamoi(res, larg);
  res = strcatamoi(res, "*");
  res = strcatamoi(res, longe);
  return (res);
}

char            *parsenameless(char *name, int test2, char *new)
{
  int           cpt;
  int           cpt2;

  cpt = -1;
  while (test2 > 0)
    if (name[++cpt] == '/')
      test2--;
  cpt2 = -1;
  while (name[++cpt] != '.')
    new[++cpt2] = name[cpt];
  new[++cpt2] = '\0';
  return (new);
}

char            *parsename(char *name)
{
  int           cpt;
  int           cpt2;
  char          *new;
  int           test;
  int           test2;

  test = 0;
  cpt = -1;
  cpt2 = 0;
  while (name[++cpt] != '\0')
    if (name[cpt] == '/')
      test++;
  test2 = test;
  cpt = -1;
  while (test > 0)
    if (name[++cpt] == '/')
      test--;
  while (name[++cpt] != '.')
    cpt2++;
  if ((new = malloc(sizeof(char) * (cpt2 + 1))) == NULL)
    exit(84);
  return (parsenameless(name, test2, new));
}

char            *parsetetri(char *name, int len, int cpt2)
{
  int           cpt;
  int           fd;
  char          *buff;
  char          buf[2];
  char          *newname;

  cpt = -1;
  newname = my_strdup("tetriminos/");
  newname = my_strcatwoman(newname, name);
  if ((fd = open(newname, O_RDONLY)) == -1)
    exit (84);
  buf[0] = 'a';
  while (buf[0] != '\n')
    {
      cpt = read(fd, buf, 1);
      buf[cpt] = '\0';
      cpt2++;
    }
  if ((buff = malloc(sizeof(char) * (len))) == NULL)
    exit(84);
  cpt2 = read(fd, buff, len);
  buff[cpt2] = '\0';
  close(fd);
  return (buff);
}

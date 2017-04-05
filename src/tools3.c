/*
** tools3.c for  in /home/lehuun_m/delivery/PSU_2016_tetris
** 
** Made by Maxime Le Huu Nho
** Login   <maxime.lehuunho@epitech.eu>
** 
** Started on  Sat Mar 18 16:45:35 2017 Maxime Le Huu Nho
** Last update Sat Mar 18 16:59:14 2017 Maxime Le Huu Nho
*/

#include "my.h"

void			my_usage(char **av, int i)
{
  my_printf("Usage\t%s [options]\nOptions:\n   ", av[0]);
  my_putstr("--help\t\t  Display this help\n   ");
  my_putstr("-l --level={num}\t  Start Tetris at level num (def:  1)\n   ");
  my_putstr("-kl --key-left={K}\t  Move the tetrimino LEFT using \
the K key ");
  my_putstr("(def:  left arrow)\n   -kr --key-right={K}    \
Move the tetrimino ");
  my_putstr("RIGHT using the K key (def:  right arrow)\n   ");
  my_putstr("-kt --key-turn={K}\t  TURN the tetrimino clockwise \
90d using the ");
  my_putstr("K key (def:  top arrow)\n   -kd --key-drop={K}\t  DROP the ");
  my_putstr("tetrimino using the K key (def:  down arrow)\n   ");
  my_putstr("-kq --key-quit={K}\t  QUIT the game using the K \
key (def:  'q' key)");
  my_putstr("\n   -kp --key-pause={K}    PAUSE/RESTART the game \
using the K key");
  my_putstr(" (def:  space bar)\n   --map-size={row,col}   Set \
the numbers of ");
  my_putstr("rows and columns of the map (def:  20,10)\n   ");
  my_putstr("-w --without-next\t  Hide next tetrimino (def:  false)\n   ");
  my_putstr("-d --debug\t\t  Debug mode (def:  false)\n");
  if (i == 0)
    exit(0);
  exit (84);
}

int			readmyscore()
{
  struct stat		sb;
  int			fd;
  char			*score;
  int			res;

  if ((fd = open("score", O_RDONLY)) == -1)
    exit(84);
  if (stat("score", &sb) == -1)
    exit(84);
  if ((score = malloc(sizeof(char) * (sb.st_size + 1))) == NULL)
    exit(84);
  if (read(fd, score, sb.st_size) == 0)
    exit(84);
  close(fd);
  score[sb.st_size] = '\0';
  res = my_getnbr(score);
  return (res);
}

int			my_powerint(int val, int pui)
{
  int			cpt;
  int			res;

  cpt = -1;
  res = 1;
  if (pui == 0)
    return (1);
  while (++cpt < pui)
    res *= val;
  return (res);
}

void			writemyscore(int score)
{
  int			fd;
  char			*hscore;

  if ((fd = open("score", O_RDWR)) == -1)
    exit(84);
  hscore = int_to_char(score);
  if (write(fd, hscore, my_strlen(hscore)) == 0)
    exit(84);
  close(fd);
}

int			good_size(char *tetri)
{
  int			cpt;
  int			val;

  cpt = -1;
  val = 0;
  while (tetri[++cpt] != '\0')
    val++;
  while (tetri[--cpt] != '*')
    val--;
  return (val);
}

/*
** my.h for  in /home/lehuun_m/delivery/PSU_2016_tetris
**
** Made by Maxime Le Huu Nho
** Login   <lehuun_m@epitech.net>
**
** Started on  Tue Feb 21 14:48:49 2017 Maxime Le Huu Nho
** Last update Sun Mar 19 17:32:49 2017 ferchaud kevin
*/

#ifndef MY_H
# define MY_H

#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>
#include <term.h>
#include <dirent.h>
#include <time.h>

typedef struct		s_data
{
  char			**av;
  int			l;
  char			*kl;
  char			*kr;
  char			*kt;
  char			*kd;
  char			*kq;
  char			*kp;
  int			mapsize[2];
  int			w;
  int			d;
}			t_data;

typedef struct		s_plat
{
  char			**game;
  struct s_list1	**tetri;
  int			nbtetri;
  int			x;
  int		        y;
  int			c;
  int			c2;
  int			line;
  int			score;
  int			highscore;
  int			mapsize[2];
}			t_plat;

typedef struct	s_list1
{
  char		**tetri;
  int		color;
  int		x;
  int		y;
}		m_list;

typedef struct  s_list2
{
  char          **name;
  char          **size;
  char          **color;
  char          **recupval;
  char          **tetri;
  int           nbtetri;
}               t_list;

typedef struct  s_list3
{
  int           cpt;
  int           cpt2;
  int           cpt3;
  int           cpt4;
  char          **ints;
}               cpt_list;

typedef t_data * (*t_args)(char *, t_data *);
typedef void (*t_touch)(t_plat **, m_list *, char **);

int		my_strlen(char *);
char		*my_strcatamoi(char *, char *);
int		my_strlena(char *);
void		my_putstr(char *);
void		my_printf(const char *, ...);
void		do_int(int);
void		do_long(long);
void		do_float(float);
void		do_char(char);
void		do_string(char *);
void		do_point(int);
void		do_short(short);
int		do_hexd(int);
int		do_binary(unsigned);
void		do_prints(char *);
int		do_modulo();
int		my_getnbr(char *);
char		*my_strdup(char *);
void		my_putchar(char);
int		my_intlenunsign(unsigned int);
char		*my_revstr(char *);
char		*strcatamoi(char *, char *);
int		my_strcmptri(char *, char *);
int		count_tetri();
int		my_strcmpamoi2(char *, char *);
t_list		*tri_tetritab(t_list *);
void		print_sure(t_list *);
t_list		*stock_tetri();
m_list		**init_mlist(t_list *);
void		print_bat();
void		print_tab(char **, int, int);
void		do_kl(t_plat **, m_list *, char **);
void		do_kr(t_plat **, m_list *, char **);
void		do_kt(t_plat **, m_list *, char **);
void		do_kd(t_plat **, m_list *, char **);
void		do_kq(t_plat **, m_list *, char **);
void		do_kp(t_plat **, m_list *, char **);
int		my_strtol(char *, char **);
int		my_getnbr(char *);
int		my_strcmptri(char *, char *);
int		my_strcmpamoi(char *, char *);
int		my_strcmpamoi2(char *, char *);
char		**create_cmd2();
char		**create_cmd();
t_data		*fill_struct(char **);
t_args		*init_args();
t_touch		*init_touch();
char		**stock_touch(t_data *);
t_data		*init_l(char *, t_data *);
t_data		*init_kl(char *, t_data *);
t_data		*init_kr(char *, t_data *);
t_data		*init_kt(char *, t_data *);
t_data		*init_kd(char *, t_data *);
t_data		*init_kq(char *, t_data *);
t_data		*init_kp(char *, t_data *);
t_data		*init_w(char *, t_data *);
t_data		*init_d(char *, t_data *);
t_data		*init_ms(char *, t_data *);
void		aff_debug(t_data *, t_list *, char **, t_plat *);
char		*int_to_char(int);
int		lenint(int);
int		my_strncmpmoi(char *, char *, int);
char		*get_elem(char **, int);
void		my_usage(char **, int);
int		readmyscore();
int		my_powerint(int, int);
void		writemyscore(int);
int		good_size(char *);
void		print_tetrimino(t_plat *, m_list *);
void		print_lettergameover(int, int, int);
void		print_space(int, int, int);
void		print_gameoverless(char **, int);
void		print_newrecord();
void		print_finalscore(int, int);
void		print_bscore(t_plat *);
void		print_gameover(t_plat *);
t_plat		*init_plat(t_data *, t_list *);
void		gest_read(int);
void		check_args(char **, char **, char **);
int		*check_cmd(char *, char **, char **);
t_data		*check_margument(char **, t_data *, char **, char **);
void		check_touch(char **, char **);
char		*check_buffer(char *, char *, char **, t_plat **);
void		print_next(t_plat *);
char		*recup_av(char *);
void		suppr_line(t_plat **, int);
int		scheck_left(m_list *, t_plat **);
int		scheck_right(m_list *, t_plat **);
void		checkline_tetri(t_plat **, t_data **, int);
void		checkend(t_plat *);
void		checkhscore(t_plat **);
void		stock_mytetri(t_plat **, m_list *);
int		stock_tetribuffer(m_list *, t_plat **);
void		print_L5less();
void		print_L5();
void		print_L1();
void		print_L2();
void		print_L3();
void		print_L4less();
void		print_L4();
char		*my_strcatwoman(char *, char *);
char		*stringmap(char *);
int		gnb1(char *);
int		gnb2(char *);
t_list		*swap_infos(t_list *, int);
char		*my_getchar(int);
char		*my_revstr(char *);
int		iserror(char *);
t_list		*list_error(t_list *, int);
int		checkforerror(char *, int);
cpt_list	*send_error(cpt_list *);
cpt_list        *changecpts(cpt_list *, char *);
int		checkextension(char *);
int             checkn(char *);
void            init_colors();
t_list          *malloc_list(t_list *, int);
t_list          *null_list(t_list *, int);
t_list          *modif_list(t_list *, int, struct stat, char *);
t_list          *make_listless(t_list *, int, int);
t_list          *make_list(t_list *, DIR *, struct stat, int);
char            *parsesize(char *, char *);
char            *parsenameless(char *, int, char *);
char            *parsename(char *);
char            *parsetetri(char *, int, int);
void            print_colorsix(int, int, int);
void            print_colorseven(int, int, int);
void            print_color(int, int, int, int);
void            print_colorone(int, int, int);
void            print_colortwo(int, int, int);
void            print_colorthree(int, int, int);
void            print_colorfour(int, int, int);
void            print_colorfive(int, int, int);
void            print_barre();
void            print_bat();
void            print_score2();
void            print_score();
void            print_tetris();
void            print_tab_bat(int, int);
void            print_tabagain(int, int);
void            print_tab(char **, int, int);
t_list          *print_tetri(t_list *);
char            **recuptetri(char *, t_list *, int);
char            **recupint(char *);
int             count_tetri();
t_list          *stock_tetri();
int		ts(int, int, char *);
m_list          **init_mlist(t_list *);
cpt_list        *init_cpts();
void		play_tetris(t_data *, char **, t_plat *);
void            print_map(t_plat *, t_data *);
void            print_play(t_plat **, t_data **, double);
int             check_level(int, t_plat **, t_data *);
void            play_tetrisless(t_plat *, char *, char **, t_data *);
char		*init_tetrirand(t_plat **);

#endif /* !MY_H */

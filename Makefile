##
## Makefile for emacs in /home/kevin.ferchaud/PSU_2016_tetris
## 
## Made by ferchaud kevin
## Login   <kevin.ferchaud@epitech.net>
## 
## Started on  Sat Mar 18 19:56:50 2017 ferchaud kevin
## Last update Sun Mar 19 17:33:39 2017 ferchaud kevin
##

NAME	=	tetris

SRC	=	src/main.c			\
		src/check_tetrimino.c		\
		src/play_tetris.c		\
		src/init.c			\
		src/init2.c			\
		src/init3.c			\
		src/print.c			\
		src/print2.c			\
		src/print3.c			\
		src/tools.c			\
		src/tools2.c			\
		src/tools3.c			\
		src/tools4.c			\
		src/do.c			\
		src/do2.c			\
		src/tab.c			\
		src/tab2.c			\
		src/check.c			\
		src/check2.c			\
		src/stock.c			\
		src/aff_tetris2.c		\
		src/aff_tetris.c		\
		src/annexe2.c			\
		src/annexe.c			\
		src/check_tetrierror.c		\
		src/init_col.c			\
		src/init_list.c			\
		src/make_list.c			\
		src/parse_tetri.c		\
		src/print_color2.c		\
		src/print_color.c		\
		src/print_game.c		\
		src/print_tab.c			\
		src/print_tetrideb.c		\
		src/recup_tetri.c		\
		src/stock_tetri.c		\
		src/test_init_tet.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

LIB	=	-L lib/my/ -lmy -lncurses

CFLAGS	=	-I include

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

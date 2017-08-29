##
## Makefile for Makefile in /home/renard_e/Makefile_lib
## 
## Made by gregoire renard
## Login   <renard_e@epitech.net>
## 
## Started on  Mon Nov  9 11:43:47 2015 gregoire renard
## Last update Sun Feb 21 16:11:37 2016 gregoire renard
##


CC	= g++

RM	= rm -fr

SRCS	= allum1.c \
	  remp_aff_map.c \
	  remp_stick.c \
	  error_fct.c \
	  game_algo.c \
	  ask_player.c \
	  moove.c \
	  start_fct.c \
	  ia_mode.c \
	  ia_line_opt.c \
	  ia_matches_opt.c \
	  aff_tours.c \
	  convert_in_char.c \
	  aff_looser_pve.c \
	  after_supr.c \
	  recover.c \
	  ask_player_complement.c \
	  douille.c \

OBJS 	= $(SRCS:.c=.o)

NAME	= allum1_ncurses

CFLAGS	= -W -Wall -Wextra -pipe -pedantic -ansi -D_GNU_SOURCE -fpermissive

all:	$(NAME)

$(NAME): $(OBJS)
	 make -C lib/my/
	 $(CC) -o $(NAME) $(OBJS) -I include/ -L lib/ -lmy -lncurses lib/libLeap.so -Wl,-rpath,lib

clean:
	$(RM) $(OBJS)
	make clean -C lib/my/
	$(RM) *~

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/my/

re: fclean all

.PHONY: all re clean fclean

##
## Makefile for Makefile in /home/renard_e/Makefile_lib
## 
## Made by gregoire renard
## Login   <renard_e@epitech.net>
## 
## Started on  Mon Nov  9 11:43:47 2015 gregoire renard
## Last update Tue Feb 16 10:12:09 2016 gregoire renard
##


CC	= gcc

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
	  aff_looser_pvp.c \
	  choose_game_algo.c \
	  opt_game.c \
	  aff_tours2.c \
	  ask_player2.c \
	  game_algo2.c \
	  after_supr.c \
	  recover.c \

OBJS 	= $(SRCS:.c=.o)

NAME	= allum1_ncurses

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJS)
	 make -C lib/my/
	 $(CC) -o $(NAME) $(OBJS) -I include/ -L lib/ -lmy -lncurses

clean:
	$(RM) $(OBJS)
	make clean -C lib/my/

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/my/

re: fclean all

.PHONY: all re clean fclean

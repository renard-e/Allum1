##
## Makefile for Makefile in /home/renard_e/Makefile_lib
## 
## Made by gregoire renard
## Login   <renard_e@epitech.net>
## 
## Started on  Mon Nov  9 11:43:47 2015 gregoire renard
## Last update Thu Feb 11 14:16:55 2016 gregoire renard
##


CC	= gcc

RM	= rm -fr

SRCS	= allum1.c \
	  remp_aff_map.c \
	  remp_stick.c \
	  game_algo_first.c \
	  ask_player.c \
	  line_opt.c \
	  matches_opt.c \
	  aff_result.c \
	  ia_mode.c \
	  ia_line_opt.c \
	  ia_matches_opt.c \
	  error_fct.c \
	  game_algo2.c \
	  opt_game.c \
	  aff_change.c \

OBJS 	= $(SRCS:.c=.o)

NAME	= allum1_bonus

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJS)
	 make -C lib/my/
	 $(CC) -o $(NAME) $(OBJS) -I include/ -L lib/ -lmy

clean:
	$(RM) $(OBJS)
	make clean -C lib/my/

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/my/

re: fclean all

.PHONY: all re clean fclean

##
## Makefile for library in /home/renard_e/Makefile/
## 
## Made by gregoire renard
## Login   <renard_e@epitech.net>
## 
## Started on  Mon Oct 12 09:42:55 2015 gregoire renard
## Last update Fri Jan 22 04:24:23 2016 gregoire renard
##

NAME	= libmy.a

SRCS	= my_putchar.c \
	  my_putstr.c \
	  my_isneg.c \
	  my_put_nbr.c \
	  my_revstr.c \
	  my_strcat.c \
	  my_strcpy.c \
	  my_strlen.c \
	  my_strncpy.c \
	  my_strstr.c \
	  my_swap.c \
	  my_getnbr.c \
	  my_sort_int_tab.c \
	  my_power_rec.c \
	  my_square_root.c \
	  my_is_prime.c \
	  my_strcmp.c \
	  my_strupcase.c \
	  my_strlowcase.c \
	  my_strcapitalize.c \
	  my_str_isalpha.c \
	  my_str_isnum.c \
	  my_str_islower.c \
	  my_str_isupper.c \
	  my_str_isprintable.c \
	  get_next_line.c \
	  my_strdup.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Werror -Wall -Wextra

CC	= gcc

RM	= rm -f

all:	$(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	cp -r libmy.a ../
	mkdir -p ../../include
	cp -r my.h ../../include/

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all re clean fclean


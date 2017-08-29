/*
** my_putstr2.c for my_putstr in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Oct 16 09:42:13 2015 gregoire renard
** Last update Fri Jan 22 04:17:23 2016 gregoire renard
*/

#include "my.h"

void	my_putstr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}

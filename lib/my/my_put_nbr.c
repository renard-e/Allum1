/*
** my_put_nbr.c for my_put_nbr in /home/renard_e/Piscine_C_J03
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Oct  1 11:05:06 2015 gregoire renard
** Last update Fri Jan 22 04:20:49 2016 gregoire renard
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	mod;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	mod = (nb % 10);
	nb = (nb - mod) / 10;
	my_put_nbr(nb);
	my_putchar(48 + mod);
	}
      else
	my_putchar(48 + nb % 10);
    }
}

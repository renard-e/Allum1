/*
** aff_change.c for aff_change in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_double
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Feb 11 13:49:56 2016 gregoire renard
** Last update Thu Feb 11 13:50:46 2016 gregoire renard
*/

#include <stdlib.h>
#include "include/my.h"

void		aff_change_player2(int matches, int line)
{
  my_putstr("Player2 removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
}

void		aff_change_player1(int matches, int line)
{
  my_putstr("Player1 removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
}

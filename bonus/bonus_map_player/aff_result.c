/*
** aff_result.c for aff_result in /home/renard_e/progElem/CPE_2015_Allum1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb  8 23:44:52 2016 gregoire renard
** Last update Wed Feb 10 09:50:35 2016 gregoire renard
*/

#include <stdlib.h>
#include "include/my.h"

void            aff_change_player2(int matches, int line)
{
  my_putstr("Player2 removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
}

void		aff_player_loose()
{
  my_putstr("Player 1 loose\n");
}

void		aff_ia_loose()
{
  my_putstr("player 2 loose\n");
}

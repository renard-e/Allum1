/*
** choose_game_algo.c for choose_game_algo in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse_double
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb 15 17:43:29 2016 gregoire renard
** Last update Mon Feb 15 19:02:19 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

int		choose_game_algo(t_start start)
{
  if (start.opt == 1)
    start.indic = game_algo2(start.map, start.size_map);
  else
    start.indic = game_algo(start.map, start.size_map);
  return (start.indic);
}

/*
** after_supr.c for after_supr in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse_double
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Tue Feb 16 09:20:21 2016 gregoire renard
** Last update Sun Feb 21 14:30:23 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

void		after_supr(char **map, t_pos *pos)
{
  aff_map(map);
  attron(A_REVERSE);
  mvprintw(pos->y, pos->x, map[pos->y]);
  attroff(A_REVERSE);
}

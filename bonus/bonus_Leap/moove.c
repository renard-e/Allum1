/*
** moove.c for moove in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Thu Feb 11 21:12:22 2016 gregoire renard
** Last update Sun Feb 21 14:33:41 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

int		calc_map(char **map)
{
  int		len;

  len = 0;
  while (map[len] != NULL)
    len++;
  return (len);
}

void		moove_down(char **map, t_pos *pos)
{
  int		len_map;

  len_map = calc_map(map);
  if (pos->y == (len_map - 2))
    pos->y = pos->y;
  else
    {
      attron(A_NORMAL);
      mvprintw(pos->y, pos->x, map[pos->y]);
      attroff(A_NORMAL);
      pos->y = pos->y + 1;
      attron(A_REVERSE);
      mvprintw(pos->y, pos->x, map[pos->y]);
      attroff(A_REVERSE);
    }
}

void		moove_up(char **map, t_pos *pos)
{
  if (pos->y == 1)
    pos->y = pos->y;
  else
    {
      attron(A_NORMAL);
      mvprintw(pos->y, pos->x, map[pos->y]);
      attroff(A_NORMAL);
      pos->y = pos->y - 1;
      attron(A_REVERSE);
      mvprintw(pos->y, pos->x, map[pos->y]);
      attroff(A_REVERSE);
    }
}

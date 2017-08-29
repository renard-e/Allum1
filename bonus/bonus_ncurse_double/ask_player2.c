/*
** ask_player2.c for ask_player2 in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse_double
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb 15 18:33:19 2016 gregoire renard
** Last update Mon Feb 15 18:37:53 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

void		douille2(char **map, t_pos *pos, int size_map)
{
  static int	tours = 0;

  attron(A_REVERSE);
  mvprintw(pos->y, pos->x, map[pos->y]);
  attroff(A_REVERSE);
  if (tours % 2 == 0)
    aff_tours_player1(size_map);
  else
    aff_tours_player2(size_map);
  tours++;
}

char		**ask_player2(char **map, t_pos *pos, int size_map)
{
  int		key;
  int		supr;

  supr = 0;
  douille2(map, pos, size_map);
  while ((key = getch()) != '\n' || supr == 0)
    {
      if (supr == 0)
        {
          if (key == KEY_DOWN)
            moove_down(map, pos);
          if (key == KEY_UP)
            moove_up(map, pos);
          if (key == ' ')
            map = supr_fct(map, pos, &supr);
        }
      else if (key == ' ')
        map = supr_fct(map, pos, &supr);
      refresh();
    }
  return (map);
}

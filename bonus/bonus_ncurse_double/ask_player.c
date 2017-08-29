/*
** ask_player.c for ask_player in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Feb 11 20:02:04 2016 gregoire renard
** Last update Tue Feb 16 11:19:37 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

void		douille(char **map, t_pos *pos,
			int size_map, int * supr)
{
  attron(A_REVERSE);
  mvprintw(pos->y, pos->x, map[pos->y]);
  attroff(A_REVERSE);
  aff_tours_player(size_map);
  *supr = 0;
}

int		cpt_stick_line(char *line)
{
  int		nb_stick;
  int		idx;

  idx = 0;
  nb_stick = 0;
  while (line[idx] != '\0')
    {
      if (line[idx] == '|')
	nb_stick++;
      idx++;
    }
  return (nb_stick);
}

char		**supr_fct(char **map, t_pos *pos, int *supr)
{
  int		idx;
  int		nb_stick;

  idx = 0;
  nb_stick = cpt_stick_line(map[pos->y]);
  if (nb_stick == 0)
    {
      if (*supr == 1)
	*supr = 1;
      else
	*supr = 0;
      return (map);
    }
  *supr = 1;
  while (map[pos->y][idx] != '|')
    idx++;
  while (map[pos->y][idx] == '|')
    idx++;
  idx--;
  map[pos->y][idx] = ' ';
  after_supr(map, pos);
  return (map);
}

char		**ask_player(char **map, t_pos *pos, int size_map)
{
  t_pla		pla;
  static int	tot_stick = 0;

  douille(map, pos, size_map, &pla.supr);
  while ((pla.key = getch()) != '\n' || pla.supr == 0)
    {
      if (pla.supr == 0)
	{
	  if (pla.key == KEY_DOWN)
	    moove_down(map, pos);
	  if (pla.key == KEY_UP)
	    moove_up(map, pos);
	  if (pla.key == ' ')
	    {
	      tot_stick = cpt_stick_line(map[pos->y]);
	      map = supr_fct(map, pos, &pla.supr);
	    }
	}
      else if (pla.key == ' ')
	map = supr_fct(map, pos, &pla.supr);
      else if (pla.key == 'r')
	map = recover(map, pos, tot_stick, &pla.supr);
      refresh();
    }
  return (map);
}

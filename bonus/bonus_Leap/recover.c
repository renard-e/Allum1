/*
** recover.c for recover in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse_double
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Tue Feb 16 09:51:32 2016 gregoire renard
** Last update Sun Feb 21 14:33:50 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

int		verif_nb_stick(int nb_stick, int tot_stick, int *supr)
{
  if (nb_stick == tot_stick)
    {
      *supr = 0;
      return (-1);
    }
  return (0);
}

int		set_last_p(char **map, t_pos *pos)
{
  int		cpt_line;
  int		last_p;

  cpt_line = my_strlen(map[0]);
  last_p = (cpt_line / 2) - pos->y + 1;
  return (last_p);
}

char		**recover_oo_stick(char **map, t_pos *pos,
				   int idex)
{
  while (map[pos->y][idex] != '|')
    idex++;
  while (map[pos->y][idex] == '|')
    idex++;
  map[pos->y][idex] = '|';
  return (map);
}

char		**recover(char **map, t_pos *pos,
			  int tot_stick, int *supr)
{
  int		nb_stick;
  int		idex;
  static int	last_p;

  last_p = 0;
  idex = 0;
  nb_stick = cpt_stick_line(map[pos->y]);
  if ((verif_nb_stick(nb_stick, tot_stick, supr)) == -1)
    return (map);
  if (nb_stick == 0)
    {
      last_p = set_last_p(map, pos);
      map[pos->y][last_p] = '|';
    }
  else
    map = recover_oo_stick(map, pos, idex);
  after_supr(map, pos);
  refresh();
  nb_stick = cpt_stick_line(map[pos->y]);
  if ((verif_nb_stick(nb_stick, tot_stick, supr)) == -1)
    return (map);
  return (map);
}

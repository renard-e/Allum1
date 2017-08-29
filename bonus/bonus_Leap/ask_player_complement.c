/*
** ask_player.c for ask_player in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Thu Feb 11 20:02:04 2016 gregoire renard
** Last update Sun Feb 21 14:31:37 2016 gregoire renard
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include "include/Leap.h"
#include "include/LeapMath.h"
#include "include/my.h"

char		**mouvement_opt(t_pos *new_pos, int *supr,
				char **map, t_pos *pos)
{
  static int            tot_stick = 0;

  if (*supr == 0)
    {
      if (new_pos->y < 200 && *supr == 0)
	moove_down(map, pos);
      else if (new_pos->y > 300 && *supr == 0)
	moove_up(map, pos);
      else if (new_pos->x < -150 && *supr == 0)
	{
	  tot_stick = cpt_stick_line(map[pos->y]);
	  map = supr_fct(map, pos, supr);
	}
    }
  else
    {
      if (new_pos->x < -150)
	map = supr_fct(map, pos, supr);
      else if (new_pos->x > 150)
	map = recover(map, pos, tot_stick, supr);
    }
  return (map);
}

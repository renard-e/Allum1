/*
** allum1.c for allum1 in /home/renard_e/progElem/CPE_2015_Allum1
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Mon Feb  8 08:52:20 2016 gregoire renard
** Last update Sat Feb 20 16:03:40 2016 rodrigue rene
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

void		free_var_fct(char **map)
{
  int		index;

 index = 0;
  while (map[index] != NULL)
    index++;
  while (index >= 0)
    {
      free(map[index]);
      index--;
    }
}

int		end_aff(int indic, int opt)
{
  int		i;

  i = 0;
  clear();
  aff_pve(indic);
  mvprintw(0, 0, "press enter to quit the game");
  while (i == 0)
    {
      if (getch() == '\n')
	i = 1;
    }
  if (endwin() == ERR)
    return (0);
  return (0);
}

void		end(char **map)
{
  free_var_fct(map);
  free(map);
}

int		main(int argc, char **argv)
{
  t_start	start;

  start.map = NULL;
  if ((start.size_map = error_fct(argc, argv)) == -1)
    return (1);
  if ((start.map = remp_map(start.map, start.size_map))
      == NULL)
    {
      my_putstr("error : malloc failure\n");
      return (1);
    }
  if (newterm(NULL, stderr, stdin) == NULL)
    return (1);
  if ((start.opt = start_fct(argc, argv)) == -1)
    return (1);
  aff_map(start.map);
  aff_tours_player(start.size_map);
  start.indic = game_algo(start.map, start.size_map);
  end_aff(start.indic, start.opt);
  end(start.map);
  return (0);
}

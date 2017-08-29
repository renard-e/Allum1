/*
** matches_opt.c for matches_opt.c in /home/renard_e/progElem/CPE_2015_Allum1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb  8 17:07:11 2016 gregoire renard
** Last update Tue Feb  9 11:51:40 2016 gregoire renard
*/

#include <stdlib.h>
#include "include/my.h"

int		test_matches(int matches, char **map, int line)
{
  int		nb_stick;
  int		cpt_l;

  nb_stick = 0;
  cpt_l = 0;
  if (matches == 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (-1);
    }
  while (map[line][cpt_l] != '\0')
    {
      if (map[line][cpt_l] == '|')
	nb_stick++;
      cpt_l++;
    }
  if (matches > nb_stick)
    {
      my_putstr("Error: not enough matches on this line\n");
      return (-1);
    }
  return (0);
}

int		matches_option(int line, char **map)
{
  char		*order_m;
  int		matches;

  my_putstr("Matches: ");
  if ((order_m = get_next_line(0)) == NULL)
    return (-2);
  if (test_range(order_m) == -1)
    {
      my_putstr("Error: not enough match(es) on this line\n");
      return (-1);
    }
  if ((test_alpha(order_m)) == -1)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  matches = my_getnbr(order_m);
  if ((test_matches(matches, map, line)) == -1)
    return (-1);
  return (matches);
}

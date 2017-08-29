/*
** ia_mode.c for ia_mode in /home/renard_e/progElem/CPE_2015_Allum1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Feb  9 08:31:52 2016 gregoire renard
** Last update Wed Feb 10 15:12:17 2016 gregoire renard
*/

#include <stdlib.h>
#include "include/my.h"

void            aff_change_ia(int matches, int line)
{
  my_putstr("AI removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
}

char		**ia_mode(char **map, int size_map)
{
  int		line;
  int		matches;

  line = -1;
  matches = -1;
  my_putstr("\nAI's turn...\n");
  while (line == -1 || matches == -1)
    {
      if ((line = ia_line_opt(map, size_map)) == -1)
	matches = -1;
      else
	matches = ia_matches_opt(map, line);
    }
  map = map_change(map, matches, line);
  aff_change_ia(matches, line);
  aff_map(map);
  return (map);
}

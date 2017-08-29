/*
** ask_player.c for ask_player in /home/renard_e/progElem/CPE_2015_Allum1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb  8 16:07:51 2016 gregoire renard
** Last update Tue Feb  9 11:39:12 2016 gregoire renard
*/

#include <stdlib.h>
#include "include/my.h"

void		aff_change(int matches, int line)
{
  my_putstr("Player removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
}

char		**map_change(char **map, int matches, int line)
{
  int		delete;
  int		index;

  index = 1;
  delete = 0;
  while (map[line][index] != '|' && map[line][index] != '\0')
    index++;
  while (map[line][index] == '|' && map[line][index] != '*')
    index++;
  index--;
  while (delete < matches)
    {
      map[line][index] = ' ';
      index--;
      delete++;
    }
  return (map);
}

char		**ask_player(char **map)
{
  int		line;
  int		matches;

  line = -1;
  matches = -1;
  my_putstr("\nYour turn:\n");
  while (line == -1 || matches == -1)
    {
      if ((line = line_option(map)) == -2)
	return (NULL);
      if (line == -1)
	matches = -1;
      else
	if ((matches = matches_option(line, map)) == -2)
	  return (NULL);
    }
  map = map_change(map, matches, line);
  aff_change(matches, line);
  aff_map(map);
  return (map);
}

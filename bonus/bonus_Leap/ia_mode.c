/*
** ia_mode.c for ia_mode in /home/renard_e/progElem/CPE_2015_Allum1
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Tue Feb  9 08:31:52 2016 gregoire renard
** Last update Sun Feb 21 14:37:49 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

void		aff_change(int line, int matches, int size_map)
{
  char		*str1;
  char		*str2;
  char		*line_str;
  char		*matches_str;

  str1 = "AI's removed ";
  str2 = " match(es) from line ";
  line_str = convert_in_char(line);
  matches_str = convert_in_char(matches);
  mvprintw(size_map + 9, 0, str1);
  mvprintw(size_map + 9, my_strlen(str1), matches_str);
  mvprintw(size_map + 9, my_strlen(str1)
	   + my_strlen(matches_str), str2);
  mvprintw(size_map + 9, my_strlen(str1)
	   + my_strlen(str2) +  my_strlen(matches_str), line_str);
  line = 0;
  while (line <= 50)
    {
      mvprintw(size_map + 9, my_strlen(str1)
	       + my_strlen(str2) +  my_strlen(matches_str)
	       + my_strlen(line_str), "                 ");
      line++;
    }
}

char		**map_change(char **map, int matches, int line)
{
  int		supr;
  int		index;

  index = 1;
  supr = 0;
  while (map[line][index] != '|' && map[line][index] != '\0')
    index++;
  while (map[line][index] == '|' && map[line][index] != '*')
    index++;
  index--;
  while (supr < matches)
    {
      map[line][index] = ' ';
      index--;
      supr++;
    }
  return (map);
}

char		**ia_mode(char **map, int size_map)
{
  int		line;
  int		matches;
  int		cpt;

  cpt = 0;
  line = -1;
  matches = -1;
  aff_tours_ia(size_map);
  refresh();
  while (line == -1 || matches == -1)
    {
      if ((line = ia_line_opt(map, size_map)) == -1)
	matches = -1;
      else
	matches = ia_matches_opt(map, line);
    }
  map = map_change(map, matches, line);
  aff_map(map);
  cpt = 0;
  while (cpt <= 1100000000)
    cpt++;
  aff_change(line, matches, size_map);
  refresh();
  return (map);
}

/*
** ia_line_opt.c for ia_line_opt in /home/renard_e/progElem/CPE_2015_Allum1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Feb  9 08:57:46 2016 gregoire renard
** Last update Sun Feb 14 23:00:38 2016 gregoire renard
*/

#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "include/my.h"

int		line_test_stick(int line, char **map)
{
  int		index;
  int		nb_stick;

  index = 0;
  nb_stick = 0;
  while (map[line][index] != '\0')
    {
      if (map[line][index] == '|')
	nb_stick++;
      index++;
    }
  return (nb_stick);
}

int		ia_line_opt(char **map, int size_map)
{
  int		line;
  int		rand_max;
  int		rand_min;
  int		nb_stick;

  rand_max = size_map + 5;
  rand_min = 1;
  srand(time(0) * getpid());
  line = rand() % (rand_max - rand_min) + rand_min;
  nb_stick = line_test_stick(line, map);
  while (nb_stick == 0)
    {
      if ((nb_stick = line_test_stick(line, map)) > 0)
	return (line);
      else
	line = rand() % (rand_max - rand_min) + rand_min;
    }
  return (line);
}

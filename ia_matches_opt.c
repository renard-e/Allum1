/*
** ia_matches_opt.c for ia_matches_opt in /home/renard_e/progElem/CPE_2015_Allum1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Feb  9 09:09:01 2016 gregoire renard
** Last update Fri Feb 19 12:09:57 2016 gregoire renard
*/

#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "include/my.h"

int		compte_stick_line(char **map, int line)
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

int		ia_matches_opt(char **map, int line)
{
  int		nb_stick;

  nb_stick = compte_stick_line(map, line);
  if (nb_stick == 1)
    return (nb_stick);
  return (nb_stick - 1);
}

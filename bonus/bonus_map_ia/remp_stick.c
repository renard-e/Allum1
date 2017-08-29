/*
** remp_stick.c for remp_stick in /home/renard_e/progElem/CPE_2015_Allum1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb  8 13:36:54 2016 gregoire renard
** Last update Mon Feb  8 14:27:45 2016 gregoire renard
*/

#include <stdlib.h>
#include "include/my.h"

char		**remp_stick(char **map, int size_y, int size_x)
{
  int		dif;
  int		idex;
  int		stick;
  int		lim;

  idex = 1;
  stick = 0;
  lim = 0;
  dif = size_x / 2;
  while (idex < size_y - 1)
    {
      while (stick <= lim)
	{
	  map[idex][dif + stick] = '|';
	  map[idex][dif - stick] = '|';
	  stick++;
	}
      stick = 0;
      lim++;
      idex++;
    }
  return (map);
}

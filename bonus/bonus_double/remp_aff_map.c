/*
** remp_aff_map_.c for remp_aff_map in /home/renard_e/progElem/CPE_2015_Allum1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb  8 10:55:10 2016 gregoire renard
** Last update Wed Feb 10 14:56:58 2016 gregoire renard
*/

#include <stdlib.h>
#include "include/my.h"

char		**remp_middle_line(char **map, int size_y, int size_x)
{
  int		cpt_m;
  int		cpt_l;

  cpt_m = 1;
  cpt_l = 0;
  while (cpt_m < size_y - 1)
    {
      while (cpt_l < size_x)
        {
	  if (cpt_l == 0)
	    map[cpt_m][cpt_l] = '*';
	  else
	    {
	      if (cpt_l == size_x - 1)
		map[cpt_m][cpt_l] = '*';
	      else
		map[cpt_m][cpt_l] = ' ';
	    }
	  cpt_l++;
        }
      cpt_l = 0;
      cpt_m++;
    }
  return (map);
}

char		**remp_first_line_last(char **map, int size_y, int size_x)
{
  int		idex;

  idex = 0;
  while (idex < size_x)
    {
      map[0][idex] = '*';
      idex++;
    }
  idex = 0;
  while (idex < size_x)
    {
      map[size_y - 1][idex] = '*';
      idex++;
    }
  idex = 0;
  map = remp_middle_line(map, size_y, size_x);
  return (map);
}

char		**remp_map(char **map, int size_map)
{
  int		size_x;
  int		size_y;
  int		idex;

  size_x = 9 + (2 * size_map);
  size_y = 6 + (1 * size_map);
  idex = 0;
  if ((map = malloc(sizeof(char *) * (size_y + 1))) == NULL)
    return (NULL);
  map[size_y] = NULL;
  while (idex < size_y)
    {
      if ((map[idex] = malloc(size_x + 1)) == NULL)
	return (NULL);
      map[idex][size_x] = '\0';
      idex++;
    }
  map = remp_first_line_last(map, size_y, size_x);
  map = remp_stick(map, size_y, size_x);
  return (map);
}

void		aff_map(char **map)
{
  int		index;

  index = 0;
  while (map[index] != NULL)
    {
      my_putstr(map[index]);
      my_putchar('\n');
      index++;
    }
}

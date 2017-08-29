/*
** allum1.c for allum1 in /home/renard_e/progElem/CPE_2015_Allum1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb  8 08:52:20 2016 gregoire renard
** Last update Wed Feb 10 16:13:27 2016 gregoire renard
*/

#include <stdlib.h>
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

int		main(int argc, char**argv)
{
  char		**map;
  int		indic;

  (void)argv;
  (void)argc;
  map = NULL;
  if ((map = remp_map(map)) == NULL)
    {
      my_putstr("error : malloc failure\n");
      return (1);
    }
  aff_map(map);
  indic = game_algo(map);
  free_var_fct(map);
  free(map);
  if (indic == -2)
    aff_player_loose();
  else if (indic == -1)
    aff_ia_loose();
  return (0);
}

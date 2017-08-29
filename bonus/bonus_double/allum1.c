/*
** allum1.c for allum1 in /home/renard_e/progElem/CPE_2015_Allum1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb  8 08:52:20 2016 gregoire renard
** Last update Thu Feb 11 14:01:56 2016 gregoire renard
*/

#include <stdlib.h>
#include "include/my.h"

void		end_aff(int indic, int opt)
{
  if (indic == -2 && opt == 0)
    aff_player_loose();
  else if (indic == -1 && opt == 0)
    aff_ia_loose();
  else if (indic == -2 && opt == 1)
    aff_player1_loose();
  else if (indic == -1 && opt == 1)
    aff_player2_loose();
}

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

int		main(int argc, char **argv)
{
  char		**map;
  int		indic;
  int		size_map;
  int		opt;

  map = NULL;
  if ((size_map = error_fct(argc, argv)) == -1)
    return (0);
  if ((opt = opt_game(argc, argv)) == -1)
    return (0);
  if ((map = remp_map(map, size_map)) == NULL)
    {
      my_putstr("error : malloc failure\n");
      return (1);
    }
  aff_map(map);
  if (opt == 0)
    indic = game_algo(map, size_map);
  else
    indic = game_algo2(map);
  free_var_fct(map);
  free(map);
  end_aff(indic, opt);
  return (0);
}

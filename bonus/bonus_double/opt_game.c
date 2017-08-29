/*
** opt_game.c for opt_game in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_double
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Feb 11 09:05:09 2016 gregoire renard
** Last update Thu Feb 11 14:26:19 2016 gregoire renard
*/

#include <stdlib.h>
#include "include/my.h"

int		check_player(char *str)
{
  int		idx;
  char		*player;

  idx = 0;
  player = "--player";
  while (str[idx] != '\0' && player[idx] != '\0')
    {
      if (str[idx] != player[idx])
	return (0);
      idx++;
    }
  if (player[idx] == '\0' && str[idx] == '\0')
    return (1);
  return (0);
}

int		check_ia(char *str)
{
  int		idx;
  char		*ia;

  idx = 0;
  ia = "--ia";
  while (str[idx] != '\0' && ia[idx] != '\0')
    {
      if (str[idx] != ia[idx])
	return (0);
      idx++;
    }
  if (ia[idx] == '\0' && str[idx] == '\0')
    return (1);
  return (0);
}

int		opt_game(int argc, char **argv)
{
  int		indic_player;
  int		indic_ia;

  if (argc < 3)
    return (0);
  if ((indic_player = check_player(argv[2])) == 1)
    return (1);
  if ((indic_ia = check_ia(argv[2])) == 1)
    return (0);
  aff_error();
  return (-1);
}

/*
** error_fct.c for error_fct in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_player
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Feb 10 13:36:13 2016 gregoire renard
** Last update Wed Feb 10 14:14:34 2016 gregoire renard
*/

#include <stdlib.h>
#include "include/my.h"

int		inspect_argv(char *nbr)
{
  int		index;

  if ((index = my_strlen(nbr)) > 2)
    return (-1);
  index = 0;
  while (nbr[index] != '\0')
    {
      if ('0' <= nbr[index] && nbr[index] <= '9')
	index++;
      else
	return (-1);
    }
  index = my_getnbr(nbr);
  return (index);
}

int		error_fct(int argc, char **argv)
{
  int		size_map;

  if (argc == 1)
    return (0);
  if (argc != 2)
    {
      my_putstr("error: ./allum1_player size_of_map\n");
      my_putstr("exemple: ./allum1_player 5\n");
      my_putstr("size_of_map max = 50\n");
      return (-1);
    }
  if ((size_map = inspect_argv(argv[1])) == -1)
    {
      my_putstr("error: bad argument\n");
      return (-1);
    }
  if (size_map > 51)
    {
      my_putstr("error: bad size_map\n");
      return (-1);
    }
  return (size_map);
}

/*
** line_opt.c for line_opt in /home/renard_e/progElem/CPE_2015_Allum1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb  8 16:49:47 2016 gregoire renard
** Last update Tue Feb  9 12:16:03 2016 gregoire renard
*/

#include <stdlib.h>
#include "include/my.h"

int		test_range(char *order)
{
  int		i;

  i = my_strlen(order);
  if (i > 9)
    return (-1);
  return (0);
}

int		test_line(int line, char **map)
{
  int		nb_line;

  nb_line = 0;
  while (map[nb_line] != NULL)
    nb_line++;
  if (line == 0)
    return (-1);
  if (line > nb_line - 2)
    return (-1);
  return (0);
}

int		test_alpha(char *order)
{
  int		cpt_l;

  cpt_l = 0;
  if (order[0] == '\0')
    return (-1);
  while (order[cpt_l] != '\0')
    {
      if ('0' <= order[cpt_l] && order[cpt_l] <= '9')
	cpt_l++;
      else
	return (-1);
    }
  return (0);
}

int		line_option(char **map)
{
  t_line	line;

  my_putstr("Line: ");
  if ((line.order_l = get_next_line(0)) == NULL)
    return (-2);
  if ((test_alpha(line.order_l)) == -1)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  if ((test_range(line.order_l)) == -1)
    {
      my_putstr("Error: this line is out of range\n");
      return (-1);
    }
  line.line = my_getnbr(line.order_l);
  if ((test_line(line.line, map)) == -1)
    {
      my_putstr("Error: this line is out of range\n");
      return (-1);
    }
  return (line.line);
}

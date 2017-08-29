/*
** start_fct.c for start_fct in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Fri Feb 12 16:10:16 2016 gregoire renard
** Last update Sun Feb 21 14:34:14 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

char		**message()
{
  char		**str;

  if ((str = malloc(sizeof(char *) * 10)) == NULL)
    return (NULL);
  str[0] = "Commande list : ";
  str[1] = "\tPut your hand down to down";
  str[2] = "\tPut your hand UP to UP";
  str[3] = "\tBack your hand  to confirm";
  str[4] = "\tPut your hand right to delete";
  str[5] = "\trPut your hand left to delete";
  str[6] = "Rules:";
  str[7] = "The last player who deletes a matche looses";
  str[8] = "Press enter to start the game ! and present a hand above the leap";
  str[9] = NULL;
  return (str);
}

int		start_fct(int argc, char **argv)
{
  char		**str;
  int		i;
  int		opt;

  i = 0;
  if (noecho() == ERR)
    return (-1);
  curs_set(0);
  if ((str = message()) == NULL)
    return (-1);
  while (str[i] != NULL)
    {
      mvprintw(i, 0, str[i]);
      i++;
    }
  i = 0;
  while (i == 0)
    {
      if (getch() == '\n')
	i = 1;
    }
  clear();
  return (0);
}

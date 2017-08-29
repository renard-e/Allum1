/*
** start_fct.c for start_fct in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Feb 12 16:10:16 2016 gregoire renard
** Last update Sun Feb 14 22:56:54 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

char		**message()
{
  char		**str;

  if ((str = malloc(sizeof(char *) * 9)) == NULL)
    return (NULL);
  str[0] = "Commande list : ";
  str[1] = "\tSpace to delete stick";
  str[2] = "\tUp to up (logic)";
  str[3] = "\tDOWN to down (logic)";
  str[4] = "\tenter to confirm the delete";
  str[5] = "Rules:";
  str[6] = "the last player who delete stick loose";
  str[7] = "press enter to start the game !!";
  str[8] = NULL;
  return (str);
}

int		start_fct()
{
  char		**str;
  int		i;

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

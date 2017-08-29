/*
** game_algo.c for game_algo in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Thu Feb 11 19:47:48 2016 gregoire renard
** Last update Sun Feb 21 14:32:17 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

int		cpt_stick(char **map)
{
  int		cpt_l;
  int		cpt_m;
  int		nb_stick;

  cpt_m = 0;
  cpt_l = 0;
  nb_stick = 0;
  while (map[cpt_m] != NULL)
    {
      while (map[cpt_m][cpt_l] != '\0')
	{
	  if (map[cpt_m][cpt_l] == '|')
	    nb_stick++;
	  cpt_l++;
	}
      cpt_m++;
      cpt_l = 0;
    }
  return (nb_stick);
}

int		cpt_stick_ia(char **map)
{
  int		cpt_l;
  int		cpt_m;
  int		nb_stick;

  cpt_m = 0;
  cpt_l = 0;
  nb_stick = 0;
  while (map[cpt_m] != NULL)
    {
      while (map[cpt_m][cpt_l] != '\0')
	{
	  if (map[cpt_m][cpt_l] == '|')
	    nb_stick++;
	  cpt_l++;
	}
      cpt_m++;
      cpt_l = 0;
    }
  if (nb_stick == 0)
    return (-2);
  return (nb_stick);
}

int		cpt_stick_player(char **map)
{
  int		cpt_l;
  int		cpt_m;
  int		nb_stick;

  cpt_m = 0;
  cpt_l = 0;
  nb_stick = 0;
  while (map[cpt_m] != NULL)
    {
      while (map[cpt_m][cpt_l] != '\0')
	{
	  if (map[cpt_m][cpt_l] == '|')
	    nb_stick++;
	  cpt_l++;
	}
      cpt_m++;
      cpt_l = 0;
    }
  if (nb_stick == 0)
    return (-1);
  return (nb_stick);
}

int		game_algo(char **map, int size_map)
{
  int		nb_stick;
  int		len;
  t_pos		pos;

  if (noecho() == ERR)
    return (0);
  keypad(stdscr, TRUE);
  curs_set(0);
  nb_stick = cpt_stick(map);
  pos.y = 1;
  len = my_strlen(map[pos.y]);
  pos.x = (COLS / 2) - (len / 2);
  while (17)
    {
      map = ask_player(map, &pos, size_map);
      if ((nb_stick = cpt_stick_player(map)) == -1)
	return (-1);
      map = ia_mode(map, size_map);
      if ((nb_stick = cpt_stick_ia(map)) == -2)
	return (-2);
    }
  return (0);
}

/*
** game_algo_first.c for game_algo_first in /home/renard_e/progElem/CPE_2015_Allum1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb  8 15:33:45 2016 gregoire renard
** Last update Wed Feb 10 09:45:11 2016 gregoire renard
*/

#include <stdlib.h>
#include "include/my.h"

int		cpt_stick_map_player2(char **map)
{
  s_stick	stick;

  stick.cpt_l = 0;
  stick.cpt_m = 0;
  stick.nb_stick = 0;
  if (map == NULL)
    return (0);
  while (map[stick.cpt_m] != NULL)
    {
      while (map[stick.cpt_m][stick.cpt_l] != '\0')
	{
	  if (map[stick.cpt_m][stick.cpt_l] == '|')
	    stick.nb_stick++;
	  stick.cpt_l++;
	}
      stick.cpt_l = 0;
      stick.cpt_m++;
    }
  if (stick.nb_stick == 0)
    return (-1);
  return (stick.nb_stick);
}

int		cpt_stick_map_player1(char **map)
{
  s_stick	stick;

  if (map == NULL)
    return (0);
  stick.cpt_l = 0;
  stick.cpt_m = 0;
  stick.nb_stick = 0;
  while (map[stick.cpt_m] != NULL)
    {
      while (map[stick.cpt_m][stick.cpt_l] != '\0')
	{
	  if (map[stick.cpt_m][stick.cpt_l] == '|')
	    stick.nb_stick++;
	  stick.cpt_l++;
	}
      stick.cpt_l = 0;
      stick.cpt_m++;
    }
  if (stick.nb_stick == 0)
    return (-2);
  return (stick.nb_stick);
}

int		cpt_stick_map(char **map)
{
  s_stick	stick;

  stick.cpt_l = 0;
  stick.cpt_m = 0;
  stick.nb_stick = 0;
  if (map == NULL)
    return (0);
  while (map[stick.cpt_m] != NULL)
    {
      while (map[stick.cpt_m][stick.cpt_l] != '\0')
	{
	  if (map[stick.cpt_m][stick.cpt_l] == '|')
	    stick.nb_stick++;
	  stick.cpt_l++;
	}
      stick.cpt_l = 0;
      stick.cpt_m++;
    }
  return (stick.nb_stick);
}

int		game_algo(char **map)
{
  int		nb_stick;

  nb_stick = cpt_stick_map(map);
  while (17)
    {
      if ((map = ask_player1(map)) == NULL)
	return (0);
      if ((nb_stick = cpt_stick_map_player1(map)) == -2)
	return (-2);
      if ((map = ask_player2(map)) == NULL)
	return (0);
      if ((nb_stick = cpt_stick_map_player2(map)) == -1)
	return (-1);
    }
  return (0);
}

/*
** game_algo2.c for game_algo2 in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_double
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Feb 11 12:34:12 2016 gregoire renard
** Last update Thu Feb 11 14:29:50 2016 gregoire renard
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

char		**ask_player2(char **map)
{
  int		line;
  int		matches;

  line = -1;
  matches = -1;
  my_putstr("\nplayer2 turn:\n");
  while (line == -1 || matches == -1)
    {
      if ((line = line_option(map)) == -2)
        return (NULL);
      if (line == -1)
        matches = -1;
      else
        if ((matches = matches_option(line, map)) == -2)
          return (NULL);
    }
  map = map_change(map, matches, line);
  aff_change_player2(matches, line);
  aff_map(map);
  return (map);
}

char		**ask_player1(char **map)
{
  int		line;
  int		matches;

  line = -1;
  matches = -1;
  my_putstr("\nplayer1 turn:\n");
  while (line == -1 || matches == -1)
    {
      if ((line = line_option(map)) == -2)
        return (NULL);
      if (line == -1)
        matches = -1;
      else
        if ((matches = matches_option(line, map)) == -2)
          return (NULL);
    }
  map = map_change(map, matches, line);
  aff_change_player1(matches, line);
  aff_map(map);
  return (map);
}

int		game_algo2(char **map)
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

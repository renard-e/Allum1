/*
** douille.c for douille in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_Leap
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun Feb 21 16:10:47 2016 gregoire renard
** Last update Sun Feb 21 16:12:20 2016 gregoire renard
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include "include/Leap.h"
#include "include/LeapMath.h"
#include "include/my.h"

void		douille(char **map, t_pos *pos,
			int size_map, int *supr)
{
  attron(A_REVERSE);
  mvprintw(pos->y, pos->x, map[pos->y]);
  attroff(A_REVERSE);
  aff_tours_player(size_map);
  *supr = 0;
}

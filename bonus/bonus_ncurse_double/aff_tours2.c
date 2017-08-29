/*
** aff_tours2.c for aff_tours2 in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse_double
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb 15 18:30:33 2016 gregoire renard
** Last update Mon Feb 15 19:02:10 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

void            aff_tours_player1(int size_map)
{
  char          *str1;
  char          *str2;
  int           len1;
  int           len2;

  str1 = "PLAYER1 TURN";
  str2 = "PLAYER2 TURN";
  len1 = my_strlen(str1);
  len2 = my_strlen(str2);
  attron(A_REVERSE);
  mvprintw(size_map + 6, (COLS /2) - (len1/2), str1);
  attroff(A_REVERSE);
  attron(A_NORMAL);
  mvprintw(size_map + 7, (COLS /2) - (len2/2), str2);
  attroff(A_NORMAL);
}

void            aff_tours_player2(int size_map)
{
  char          *str1;
  char          *str2;
  int           len1;
  int           len2;

  str1 = "PLAYER1 TURN";
  str2 = "PLAYER2 TURN";
  len1 = my_strlen(str1);
  len2 = my_strlen(str2);
  attron(A_NORMAL);
  mvprintw(size_map + 6, (COLS /2) - (len1/2), str1);
  attroff(A_NORMAL);
  attron(A_REVERSE);
  mvprintw(size_map + 7, (COLS /2) - (len2/2), str2);
  attroff(A_REVERSE);
}

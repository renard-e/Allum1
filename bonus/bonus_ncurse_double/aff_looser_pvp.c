/*
** aff_looser_pvp.c for aff_looser_pvp in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse_double
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Feb 15 17:58:02 2016 gregoire renard
** Last update Mon Feb 15 18:00:14 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

void            player1_looser()
{
  attron(A_REVERSE);
  mvprintw(LINES/2, (COLS /2) -
           (my_strlen("PLAYER1 LOOSE")/2), "PLAYER1 LOOSE");
  attroff(A_REVERSE);
}

void            player2_looser()
{
  attron(A_REVERSE);
  mvprintw(LINES/2, (COLS /2) -
           (my_strlen("PLAYER2 LOOSE")/2), "PLAYER2 LOOSE");
  attroff(A_REVERSE);
}

void		aff_pvp(int indic)
{
  if (indic == -1)
    player1_looser();
  else
    player2_looser();
}

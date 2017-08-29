/*
** aff_looser.c for aff_looser in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun Feb 14 23:18:52 2016 gregoire renard
** Last update Mon Feb 15 09:31:02 2016 gregoire renard
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include "include/my.h"

void		player_looser()
{
  attron(A_REVERSE);
  mvprintw(LINES/2, (COLS /2) -
	   (my_strlen("PLAYER LOOSE")/2), "PLAYER LOOSE");
  attroff(A_REVERSE);
}

void		ia_looser()
{
  attron(A_REVERSE);
  mvprintw(LINES/2, (COLS /2) -
	   (my_strlen("IA LOOSE")/2), "iA LOOSE");
  attroff(A_REVERSE);
}

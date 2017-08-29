/*
** ask_player.c for ask_player in /home/renard_e/progElem/CPE_2015_Allum1/bonus/bonus_ncurse
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Thu Feb 11 20:02:04 2016 gregoire renard
** Last update Sun Feb 21 16:13:18 2016 gregoire renard
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include "include/Leap.h"
#include "include/LeapMath.h"
#include "include/my.h"

using namespace Leap;

class SampleListener : public Listener
{
 public:
  void onFrame(const Controller&, t_pos *new_pos);

 private:
};

void    SampleListener::onFrame(const Controller& controller, t_pos *new_pos)
{
  Leap::Frame frame = controller.frame ();
  Leap::Hand hand = frame.hands().frontmost();
  Leap::Vector position = hand.palmPosition();
  Leap::Matrix basis = hand.basis();
  Leap::Vector xBasis = basis.xBasis;
  Leap::Vector yBasis = basis.yBasis;
  Leap::Vector zBasis = basis.zBasis;
  new_pos->x = (int)position.x;
  new_pos->y = (int)position.y;
  new_pos->z = (int)position.z;
  new_pos->nb_hands = frame.hands().count();
  new_pos->geste_valid = frame.gestures().count();
}

int		cpt_stick_line(char *line)
{
  int		nb_stick;
  int		idx;

  idx = 0;
  nb_stick = 0;
  while (line[idx] != '\0')
    {
      if (line[idx] == '|')
	nb_stick++;
      idx++;
    }
  return (nb_stick);
}

char		**supr_fct(char **map, t_pos *pos, int *supr)
{
  int		idx;
  int		nb_stick;

  idx = 0;
  nb_stick = cpt_stick_line(map[pos->y]);
  if (nb_stick == 0)
    {
      if (*supr == 1)
	*supr = 1;
      else
	*supr = 0;
      return (map);
    }
  *supr = 1;
  while (map[pos->y][idx] != '|')
    idx++;
  while (map[pos->y][idx] == '|')
    idx++;
  idx--;
  map[pos->y][idx] = ' ';
  after_supr(map, pos);
  return (map);
}

char			**ask_player(char **map, t_pos *pos, int size_map)
{
  int			supr;
  SampleListener	listener;
  Controller		controller;
  t_pos			new_pos;

  douille(map, pos, size_map, &supr);
  controller.addListener(listener);
  while (supr == 0 || new_pos.z < 150)
    {
      listener.onFrame(controller, &new_pos);
      if (new_pos.nb_hands == 1)
	map = mouvement_opt(&new_pos, &supr, map, pos);
      refresh();
      usleep(199500);
    }
  return (map);
}

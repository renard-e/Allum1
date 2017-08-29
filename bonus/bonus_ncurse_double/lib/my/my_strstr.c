/*
** my_strstr.c for my_strstr in /home/renard_e/Piscine_C_J06/ex_05
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Oct  6 12:28:07 2015 gregoire renard
** Last update Fri Jan 22 04:22:11 2016 gregoire renard
*/

#include "my.h"

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  char	*chaine;
  int	taille;

  i = 0;
  j = 0;
  taille = my_strlen(to_find);
  while (str[i] != to_find[j])
    {
      i = i + 1;
    }
  while (str[i] == to_find[j])
    {
      i = i + 1;
      j = j + 1;
      if (j == taille)
	chaine = &to_find[j];
    }
  return (chaine);
}

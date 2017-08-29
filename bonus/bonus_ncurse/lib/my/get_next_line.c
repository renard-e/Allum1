/*
** get_next_line.c for get_next_line in /home/renard_e/CPE_2015_getnextline
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Jan  4 14:24:45 2016 gregoire renard
** Last update Thu Jan 21 18:38:23 2016 gregoire renard
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char		*my_realloc(char *line, int new)
{
  char		*tempo;
  int		i;

  i = 0;
  if ((tempo = malloc(new)) == NULL)
    return (NULL);
  if (line == NULL)
    {
      free(line);
      tempo[0] = 0;
      return (tempo);
    }
  else
    {
      while (line[i] != '\0')
	{
	  tempo[i] = line[i];
	  i = i + 1;
	}
    }
  tempo[i] = '\0';
  free(line);
  return (tempo);
}

int		my_strlen_combi(char *line, char *buffer)
{
  int		cpt_l;
  int		cpt_b;
  int		so;

  cpt_l = 0;
  cpt_b = 0;
  if (line == NULL)
    cpt_l = 0;
  else
    while (line[cpt_l] != '\0')
      cpt_l = cpt_l + 1;
  while (buffer[cpt_b] != '\0')
    cpt_b = cpt_b + 1;
  so = cpt_l + cpt_b + 1;
  return (so);
}

char		*buffer_analysis(char *buffer, int *cpt_buf)
{
  static char	*line;
  static int	cpt_line = 0;
  t_gnl		gnl;

  gnl.len = my_strlen_combi(line, buffer);
  if ((line = my_realloc(line, gnl.len)) == NULL)
    return (NULL);
  while (buffer[*cpt_buf] != '\n' && buffer[*cpt_buf] != '\0')
    {
      line[cpt_line] = buffer[*cpt_buf];
      cpt_line = cpt_line + 1;
      *cpt_buf = *cpt_buf + 1;
    }
  if (buffer[*cpt_buf] == '\0')
    *cpt_buf = 0;
  else
    {
      line[cpt_line] = '\0';
      gnl.save = line;
      line = NULL;
      cpt_line = 0;
      *cpt_buf = *cpt_buf + 1;
      return (gnl.save);
    }
  return (NULL);
}

int		line_reduce(int fd, t_gnl *gnl,
			    char (*buffer)[READ_SIZE + 1])
{
  if (READ_SIZE < 1 || fd == -1)
    return (-1);
  (*buffer)[READ_SIZE] = '\0';
  gnl->ret = 1;
  return (0);
}

char		*get_next_line(const int fd)
{
  static int	cpt_buf = 0;
  static char	buffer[READ_SIZE + 1];
  static char	*line;
  t_gnl		gnl;

  if ((line_reduce(fd, &gnl, &buffer)) == -1)
    return (NULL);
  while (gnl.ret > 0)
    if (line == NULL && cpt_buf == 0)
      {
	if ((gnl.ret = read(fd, buffer, READ_SIZE)) == -1)
	  return (NULL);
	buffer[gnl.ret] = 0;
	line = buffer_analysis(buffer, &cpt_buf);
      }
    else if (line == NULL && cpt_buf != 0)
      line = buffer_analysis(buffer, &cpt_buf);
    else if (line != NULL && cpt_buf != 0)
      {
	gnl.save = line;
	line = NULL;
	return (gnl.save);
      }
  free(line);
  return (NULL);
}

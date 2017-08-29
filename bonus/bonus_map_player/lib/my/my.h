/*
** my.h for my.h in /home/renard_e/systeme_unix/PSU_2015_my_printf
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Nov 13 14:28:11 2015 gregoire renard
** Last update Wed Feb 10 14:06:02 2016 gregoire renard
*/

#ifndef MY_H_
# define MY_H_

typedef struct	s_line
{
  char		*order_l;
  int		line;
}		t_line;

typedef struct	s_cpt_stick
{
  int		cpt_l;
  int		cpt_m;
  int		nb_stick;
}		s_stick;

int	error_fct(int argc, char **argv);

void	aff_change_player2(int matches, int line);

int	test_range(char *order);

void	aff_change(int matches, int line);

char	**map_change(char **map, int matches, int line);

int	ia_matches_opt(char **map, int line);

int	ia_line_opt(char **map);

char	**ia_mode(char **map);

void	aff_player_loose();

void	aff_ia_loose();

int	test_alpha(char *order);

int	matches_option(int line, char **map);

int	line_option(char **map);

char	**ask_player2(char **map);

char	**ask_player1(char **map);

int	game_algo(char **map);

char	**remp_stick(char **map, int size_y, int size_x);

char	**remp_map(char **map, int size_map);

void	aff_map(char **map);

char	*get_next_line(const int fd);

void	my_putchar(char c);

void	my_isneg(int nb);

void	my_put_nbr(int nb);

int	my_swap(int *a, int *b);

void	my_putstr(char *str);

int	my_strlen(char *str);

int	my_getnbr(char *str);

void	my_sort_int_tab(int *tab, int size);

int	my_power_rec(int nb, int power);

int	my_square_root(int nb);

int	my_is_prime(int nombre);

char	*my_strcpy(char *dest, char *src);

char	*my_strncpy(char *dest, char *src, int nb);

char	*my_revstr(char *str);

char	*my_strstr(char *str, char *to_find);

int	my_strcmp(char *s1, char *s2);

int	my_strncmp(char *s1, char *s2, int nb);

char	*my_strupcase(char *str);

char	*my_strdup(char *str);

char	*my_strlowcase(char *str);

char	*my_strcapitalize(char *str);

int	my_str_isalpha(char *str);

int	my_str_isnum(char *str);

int	my_str_islower(char *str);

int	my_str_isupper(char *str);

int	my_str_isprintable(char *str);

int	my_showstr(char *str);

int	my_showmem(char *str, int size);

char	*my_strcat(char *dest, char *src);

char	*my_strncat(char *dest, char *src, int nb);

#endif /* !MY_H_ */
